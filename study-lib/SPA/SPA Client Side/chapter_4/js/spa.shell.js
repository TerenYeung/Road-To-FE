/**
 * spa.shell.js
 * Shell module for SPA
 */

/**
 * jslint browser: true, continue: true, devel: true, indent: 2, maxerr: 50, newcap: true, nomen: true, plusplus: true, regexp: true, sloppy: true, vars: false, white: true
 */

/* global $, spa */
spa.shell = (function () {
  //---- BEGIN MODULE SCOPE VARIABLES ----
  var
    configMap = {
      anchor_schema_map: {
        chat: {
          opened: true,
          closed: true,
        }
      },
      main_html: `
      <div class="spa-shell-head">
        <div class="spa-shell-head-logo"></div>
        <div class="spa-shell-head-acct"></div>
        <div class="spa-shell-head-search"></div>
      </div>
      <div class="spa-shell-main">
        <div class="spa-shell-main-nav"></div>
        <div class="spa-shell-main-content"></div>
      </div>
      <div class="spa-shell-foot"></div>
      <div class="spa-shell-chat"></div>
      <div class="spa-shell-modal"></div>
      `,
      chat_extend_time: 250,
      chat_retract_time: 300,
      chat_extend_height: 450,
      chat_retract_height: 15,
      chat_extended_title: 'Click to retract',
      chat_retract_title: 'Click to extend',
    },
    //---- DYNAMIC STATE ----
    stateMap = {
      $container: null,
      anchor_map: {},
      is_chat_retracted: true,
    },
    //---- JQUERY CACHE
    jqueryMap = {},
    copyAnchorMap,
    setJqueryMap, toggleChat,
    changeAnchorPart, onHashchange, setChatAnchor,
    onClickChat, initModule;
    //---- END MODULE SCOPE VARIABLES ----
    
    //---- BEGIN UTILITY METHODS ----
    copyAnchorMap = function() {
      return $.extend(true, {}, stateMap.anchor_map)
    }
    //---- END UTILITY METHODS ----

    //---- BEGIN DOM METHODS ----
    // Begin DOM method: setJqueryMap
    setJqueryMap = function() {
      var $container = stateMap.$container
      jqueryMap = {
        $container: $container,
      }
    }
    // End DOM method: setJqueryMap

    // Begin DOM method: toggleChat
    // purpose: Extends or retracts chat slider
    toggleChat = function(do_extend, callback) {
      var
        px_chat_ht = jqueryMap.$chat.height(),
        is_open = px_chat_ht === configMap.chat_extend_height,
        is_closed = px_chat_ht === configMap.chat_retract_height,
        is_sliding = ! is_open && !is_closed

        // avoid race condition
        if (is_sliding) return false

        // Begin extend chat slider
        if (do_extend) {
          jqueryMap.$chat.animate({
            height: configMap.chat_extend_height
          },
          configMap.chat_extend_time,
          function() {
            jqueryMap.$chat.attr('title', configMap.chat_extended_title)
            stateMap.is_chat_retracted = false
            if (callback) callback(jqueryMap.$chat)
          })
          return true
        }
        // End extend chat slider

        // Begin retract chat slider
        jqueryMap.$chat.animate({
          height: configMap.chat_retract_height
        },
        configMap.chat_retract_time,
        function() {
          jqueryMap.$chat.attr('title', configMap.chat_retracted_title)
          stateMap.is_chat_retracted = true
          if (callback) callback(jqueryMap.$chat)
        })
        return true
        // End retract chat slider
    }
    // End DOM method: toggleChat

    // Begin DOM method: changeAnchorPart
    changeAnchorPart = function(arg_map) {
      var
        anchor_map_revise = copyAnchorMap(),
        bool_return = true,
        key_name, key_name_dep

      // Begin merge change into anchor map
      KEYVAL:
      for (key_name in arg_map) {
        if (arg_map.hasOwnProperty( key_name)) {
          // skip dependent keys
          if (key_name.indexOf('_') === 0) { continue KEYVAL }
          // update independent key value
          anchor_map_revise[key_name] = arg_map[key_name]

          // update matching dependent key
          key_name_dep = '_' + key_name
          if (arg_map[key_name_dep]) {
            anchor_map_revise[key_name_dep] = arg_map[key_name_dep]
          } else {
            delete anchor_map_revise[key_name_dep]
            delete anchor_map_revise['_s' + key_name_dep]
          }
        }
      }
      // End merge changes into anchor map

      // Begin attempt to update URI; revert if not successful
      try {
        $.uriAnchor.setAnchor( anchor_map_revise )
      } catch (err) {
        // replace URI with existing state
        $.uriAnchor.setAnchor( stateMap.anchor_map, null, true)
        bool_return = false
      }
      // End attemp to update URI
    }
    // End DOM method: changeAnchorPart
    //---- END DOM METHODS ----

    //---- BEGIN EVENT HADNLERS ----
    onHashchange = function (e) {
      var
        anchor_map_previous = copyAnchorMap(),
        anchor_map_proposed,
        _s_chat_previous, _s_chat_proposed,
        s_chat_proposed, anchor_map_proposed,
        is_ok = true,
        anchor_map_previous = copyAnchorMap()

        // attempt to parse anchor
        try {
          anchor_map_proposed = $.uriAnchor.makeAnchorMap()
        } catch (err) {
          $.uriAnchor.setAnchor(anchor_map_previous, null, true)
          return false
        }
        stateMap.anchor_map = anchor_map_proposed
        _s_chat_previous = anchor_map_previous._s_chat
        _s_chat_proposed = anchor_map_proposed._s_chat

        // Begin adjust chat component if changed
        if (!anchor_map_previous || _s_chat_previous !== _s_chat_proposed) {
          s_chat_proposed = anchor_map_proposed.chat
          switch (s_chat_proposed) {
            case 'opened':
              is_ok = spa.chat.setSliderPosition('opened')
            break
            case 'closed':
              is_ok = spa.chat.setSliderPosition('closed')
            break
            default:
              spa.chat.setSliderPosition('closed')
              delete anchor_map_proposed.chat
              $.uriAnchor.setAnchor(anchor_map_proposed, null, true)
          }
        }
        // End adjust chat component if changed

        // Begin revert anchor if slider change denied
        if (!is_ok) {
          if (anchor_map_previous) {
            $.uriAnchor.setAnchor(anchor_map_previous, null, true)
            stateMap.anchor_map = anchor_map_previous
          }
        } else {
          delete anchor_map_proposed.chat
          $.uriAnchor.setAnchor(anchor_map_proposed, null, true)
        }
        // End revert anchor if slider change denied
        return false
    }
    
    setChatAnchor = function(position_type) {
      return changeAnchorPart({chat: position_type})
    }

    onClickChat = function(e) {
      changeAnchorPart({
        chat: (stateMap.is_chat_retracted ? 'open' : 'closed')
      })
      return false
    }
    //---- END EVENT HANDLERS

    //---- BEGIN PUBLIC METHODS ----
    // Begin Public method: initModule
    initModule = function($container) {
      stateMap.$container = $container
      $container.html(configMap.main_html)
      setJqueryMap()
      
      // configure uriAnchor to use our schema
      $.uriAnchor.configModule({
        schema_map: configMap.anchor_schema_map
      })
      spa.chat.configModule({
        set_chat_anchor: setChatAnchor,
        chat_model: spa.model.chat,
        people_model: spa.model.people,
      })
      spa.chat.initModule( jqueryMap.$container )
      $(window)
        .bind('hashchange', onHashchange)
        .trigger('hashchange')

      // test toggle
      // setTimeout(()=>{toggleChat(true)}, 3000)
      // setTimeout(()=>{toggleChat(false)}, 8000)
    }
    // End PUBLIC method: initModule
    return { initModule: initModule }
    //---- END PUBLIC MOTHODS ----
}())