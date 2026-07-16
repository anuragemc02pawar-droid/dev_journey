const express = require('express')
const blog = require('./routes/blog');
const shop = require('./routes/shop');

const app = express()
const port = 3000


app.use(express.static("public"))
app.use('/blog', blog);
app.use('/shop', shop);

app.get('/', (req, res) => {
    console.log("Hey this is a get request")
  res.send('Hello World5...')
})

app.post('/', (req, res) => {
    console.log("hello this is a post request")
  res.send('Hello world post.....')
})

app.put('/', (req, res) => {
    console.log("hello this is a put request")
  res.send('Hello world put....')
})

app.get("/index", (req, res) => {
    console.log("Hey this is index")
  res.sendFile('templates/index.html', {root: __dirname})
})

app.get("/api", (req, res) => {
    res.json({a:1, b:17, c:21, name: ["alla", "bulla"]})
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})