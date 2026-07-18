const express = require('express')
const app = express()
const port = 3000
const mongoose = require('mongoose');
const employee = require("./models/employee")

mongoose.connect('mongodb://127.0.0.1:27017/company');

app.set('view engine', 'ejs');

const getRandom = (arr)=>{
let rno=Math.floor(Math.random()* (arr.length-1))
return arr[rno]
}

app.get('/', (req, res) => {
    res.render('index', { foo: 'FOO' });
})

app.get('/generate', async (req, res) => {
    await employee.deleteMany({})
    let randomNames=['Rohan', 'Sohan', "Mohan", "Shobhan"]
    let randomLang=["Python","js", "c++", "java"]
    let randomCities=["Bilaspur", "jodhpur", "kanpur", "Bijapur"]
    for (let index = 0; index < 10; index++) {
        let e = await employee.create({
            name: getRandom(randomNames),
            salary: Math.floor(Math.random()*2000000),
            language: getRandom(randomLang),
            city: getRandom(randomCities),
            isManager: Math.random()>0.5
        })
        console.log(e)
    }
    res.send("Done")

})//generate random data


app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})