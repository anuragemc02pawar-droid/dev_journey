console.log("This is about Strings")
let a="Anurag"
console.log(a[0])
console.log(a[1])
console.log(a[2])
console.log(a[3])
console.log(a[4])
console.log(a[5])
console.log(a.length)

let real_name="Anurag"
let friend="Yash"
// console.log("His name is " + real_name + " and his friend's name is " + friend)
console.log(`His name is ${real_name} and his friend's name is ${friend}`)

console.log(a.toUpperCase())
console.log(a.slice(3,6))
console.log(a.replace("Anu", "knew"))
// first occurance will only get replaced
console.log(a.concat(friend))