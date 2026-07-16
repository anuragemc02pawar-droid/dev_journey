const express = require('express')
const { connected } = require('node:process')
const app = express()
const port = 3000

app.use(express.static('public'))

app.get('/', (req, res) => {
  res.send('Hello   jjjiiii!')
})

app.get('/about', (req, res) => {
  res.send('About Us!')
})

app.get('/contact', (req, res) => {
  res.send('Contact Us')
})

app.get('/blog', (req, res) => {
  res.send('Blog!')
})

app.get('/blog/:slug/:second', (req, res) => {
    //logic to fetch slug from db
    //for url - http://localhost:3000/blog/lauda/chuchi?mode=dark&region=in
    console.log(req.params)
    console.log(req.query)
    console.log(req)
  res.send(`hello ${req.params.slug} and ${req.params.second}`)
})

app.listen(port, () => {
  console.log(`Server running at "http://localhost:${port}"`)
})