/**
 * spa.chat.js
 * Chat feature module for SPA
 */

/**
 * jslint browser: true, continue: true, devel: true, indent: 2, maxerr: 50, newcap: true, nomen: true, plusplus: true, regexp: true, sloppy: true, vars: false, white: true
 */
/** global $, spa */
spa.chat = (function(){
//---- BEGIN MODULE SCOPE VARIABLES ----
var
  configMap = {
    main_html: `
      <div style="padding:1em; color:#fff">
        Say hello to chat
      </div>
    `,
    settable_map: {}
  },
  stateMap = { $container: null },
  jqueryMap = {},
  setJqueryMap, configModule, initModule
  //---- END MODULE SCOPE VARIABLES ----
  //---- BEGIN UTILITY METHODS ----
  //---- END UTILITY METHODS ----
  //---- BEGIN DOM METHODS ----
  // Begin DOM method: setJqueryMap
  setJqueryMap = function() {
    var $container = stateMap.$container
    jqueryMap = { $container: $container }
  }
  //---- END DOM METHODS ----

  //---- BEGIN EVENT HANDLERS ----
  //---- END EVENT HANDLERS ----

  //---- BEGIN PUBLIC METHODS ----
  configModule = function(input_map) {
    spa.util.setConfigMap({
      input_map: input_map,
      settable_map: configMap.settable_map,
      config_map: configMap,
    })
    return true
  }
  // End public method: configModule

  // Begin public method: initModule
  initModule = function($container) {
    $container.html( configMap.main_html )
    stateMap.$container = $container
    setJqueryMap()
    return true
  }
  // End public method: initModule

  return {
    configModule: configModule,
    initModule: initModule,
  }
  //---- END PUBLIC METHODS ----
}())