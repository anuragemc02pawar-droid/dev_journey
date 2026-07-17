const express = require('express')
const blog = require('./routes/blog');
const app = express()
const port = 3000
const fs=require("fs")


// ...

app.use('/blog', blog);

//middleware 1- logger for our application
app.use((req, res, next) => {
    console.log(req.headers)
    req.lulla="lulla le"
    fs.appendFileSync("logs.txt",`${Date.now()} is a ${req.method}\n`)
    console.log(`${Date.now()} is a ${req.method}`);
    next();
});

//middleware 5
app.use((req, res, next) => {
    console.log('m2');
    req.lulla ="lund lele"
    next();
});


app.get('/', (req, res) => {
    res.send('Hello World!')
})
app.get('/about', (req, res) => {
    res.send('Hello World!' + req.lulla)
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})