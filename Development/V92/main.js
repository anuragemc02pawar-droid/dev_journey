const express = require('express')
const app = express()
const port = 3000

app.set('view engine', 'ejs');

app.get('/', (req, res) => {
    let siteName="Adibas"
    let searchText="Search Now"
    let arr=["Hey",1,99,199]
  res.render("index.ejs",{siteName:siteName, searchText:searchText, arr})
})

app.get('/blog/:slug', (req, res) => {
    let blogTitle="Adibas or Adidas"
    let blogContent="Worst brand ever?"
  res.render("blogpnost.ejs",{blogTitle:blogTitle, blogContent:blogContent})
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})