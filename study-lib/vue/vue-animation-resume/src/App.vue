<template>
  <div>
    <div id="app">
      <pre>
        {{code}}
      </pre>
    </div>
    <div v-html="styleCode">
    </div>
  </div>
</template>

<script>
// http://js.jirengu.com/qaquv/3/edit
export default {
  name: 'app',
  components: {
  },
  data() {
    return {
      code: ``,
      finalCode: `
      /* 大家好，我叫Teren */
        body {
          background: #ddd;
          color: red
        }
      `
    }
  },
  created() {
    let n = 0
    let str = this.code
    setInterval(()=>{
      let str
      this.code = this.finalCode.substring(0, n)

      n += 1
    }, 50)
  },
  computed: {
    styleCode() {
      return `<style>${this.code}</style>`
    }
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
</style>
