import express from "express"
import cors from "cors"
const app = express()
const port = 3000
import bodyParser from "body-parser"


//import body-parser to make it work      not necessary you can use express.json()

app.use(cors())
app.use(express.json())

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.post('/', (req, res) => {
    console.log(req.body)
    res.send("Data received")
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})