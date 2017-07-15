/**
 * const obj = {
 *    name: 'teren',
 *    age: 18,
 *    height: '175cm'
 * }
 * const result = only(obj, 'name height')
 */
module.exports = function(obj, keys) {
  obj = obj || {}
  if ('string' == keys) keys = keys.split(/ +/)
  return keys.reduce(function(ret, key) {
    if ( null == obj[key]) return ret
    ret[key] = obj[key]
    return ret
  }, {})
}