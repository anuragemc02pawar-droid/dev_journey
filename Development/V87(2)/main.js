const fs = require("fs")
// console.log(fs)

console.log("starting")
// fs.writeFileSync("anurag.txt", "Anurag is a bad boy")
fs.writeFile("anurag2.txt", "Anurag is a bad boy", ()=>{
    console.log("done")
    fs.readFile("anurag2.txt", (error,data)=>{
        console.log(error,data.toString())
    })
})

fs.appendFile("anurag.txt", " maa ke lode", (e,d)=>{
    console.log(d)
})
console.log("ending")