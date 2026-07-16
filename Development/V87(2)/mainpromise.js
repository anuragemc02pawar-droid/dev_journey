import fs from "fs/promises"

let a=await fs.readFile("anurag.txt")

console.log(a.toString())

let b=await fs.appendFile("anurag.txt", "madarchod")
console.log(a.toString,b)