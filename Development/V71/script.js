// console.log(document.querySelector(".box"))
// console.log(document.querySelector(".box").innerHTML)
// console.log(document.querySelector(".container").innerHTML)
// console.log(document.querySelector(".container").innerText)
// console.log(document.querySelector(".container").tagName)
// console.log(document.querySelector(".container").nodeName)
// document.querySelector(".container").hidden =true
// document.querySelector(".box").innerHTML='Hey I am Anurag'

let div=document.createElement("div")
div.innerHTML= "I am not the <b>same</b>"
div.setAttribute("class", "created")
document.querySelector(".container").append(div)

let cont=document.querySelector(".container")
cont.insertAdjacentHTML("afterend", "I am under the water")
