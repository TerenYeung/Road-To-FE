const Koa = require('koa')
const app = new Koa()
const http = require('http')
// demo1
// x-response-time
app.keys = ['im a newer secret', 'i like turtle'];

app.use(async function(ctx, next) {
  const start = new Date();
  await next()
  const ms = new Date() - start;
  ctx.set('X-Response-Time', `${ms}ms`);
});

// logger
app.use(async function(ctx, next) {
  const start = new Date();
  await next();
  const ms = new Date() - start;
  console.log(`${ctx.method} ${ctx.url} - ${ms}`);
});

// response

app.use(ctx => {
  // var i = 0
  // while(i < 1000000000000) {
  //   i+=1
  // }
  ctx.cookies.set('name', 'teren', {signed: true})
  ctx.body = 'Hello World'
  ctx.throw(400, 'name required', {user: 'ha...'});
}).listen(3000)


// app.listen
// the same as

// http.createServer(app.callback()).listen(3000)
http.createServer(app.callback()).listen(3001);

// app.callback()

// app.on('error', err => console.log('server errodsfsdfr', err))
