console.log("Anurag")
let Bullas=document.getElementsByClassName("box")
console.log(Bullas)
Bullas[2].style.backgroundColor="chocolate"

document.getElementById("redbox").style.backgroundColor="red"
document.querySelector(".box").style.backgroundColor="green" /*first of all .box */
// document.querySelectorAll(".box").style.color="pink" not possible 
document.querySelectorAll(".box").forEach(e=>{
    e.style.color="yellow"
})

console.log(document.getElementsByTagName("div"))

e=document.getElementsByTagName("div")
console.log(e[4].matches("#redbox"))
console.log(e[5].matches("#redbox"))
console.log(e[5].closest("#redbox"))
console.log(e[5].closest(".container"))

console.log(document.querySelector(".container").contains(e[2]))
console.log(document.querySelector(".container").contains(e[0]))
console.log(document.querySelector("body").contains(document.querySelector(".container")))