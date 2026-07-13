let a=prompt("Enter first number")
let b=prompt("Enter second number")

if(isNaN(a) || isNaN(b)){
    throw SyntaxError("This is not allowed")
}
let sum=parseInt(a)+parseInt(b) //without parsing, it will return ab string

function main(){
    let x=1
try {
    console.log("The sum is: ", sum*x)
    return true
} catch (error) {
    console.log("Error hai bhai")    //in functions without finally wont run that statement just with console.log when returning
    return false
}
finally{
    console.log("Files and db are being closed")
}

console.log("The sum is: ", sum)
}
let c=main()