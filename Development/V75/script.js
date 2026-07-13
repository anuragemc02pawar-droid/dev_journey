console.log("Anurag is a hacker")
console.log("Bullah is a hecker")

setTimeout(() => {
    console.log("This will be skipped and printed later as it's asynchronous")
}, 2000);

console.log("The End")

const callback=(arg) => { 
    console.log(arg)
 }
const loadScript=(src, callback) => { 
    let sc=document.createElement("script")
    sc.src=src
    sc.onload=callback("Anurag")
    document.head.append(sc)
 }
 loadScript("https://cdnjs.cloudflare.com/ajax/libs/prism/9000.0.1/prism.min.js", callback)