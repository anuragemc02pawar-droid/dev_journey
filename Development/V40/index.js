console.log("This is about Loops")
let a=1;
for(let i=0;i<100;i++){
    console.log(a+i)
}
let obj={
    name:"Anurag",
    role:"Programmer",
    company:"Microsoft"
}
for (const key in obj) {    
    const element = obj[key];
    console.log(key, element)  
}
for (const c of "Anurag") {
    console.log(c)
}
let s=0;
while(s<7){
    console.log(s)
    s++;
}
let t=10;
do {
    console.log(t)
} while (t<7);