function nice(name) {
    console.log("Hey " + name + " you are nice!")
    console.log("Hey " + name + " you are good!")
    console.log("Hey " + name + " you are brilliant!")
    console.log("Hey " + name + " you are better!")
    console.log("Hey " + name + " you are intellectual!")
}

nice("Anurag")

function prod(a, b) {
    // console.log(a*b)
    return a*b;
}
result=prod(5, 6)
// prod(4, 5)
console.log("The prouct of these numbers is:",result)

const func1 = (x)=>{
    console.log("I am an arrow function", x)
}
func1(37)