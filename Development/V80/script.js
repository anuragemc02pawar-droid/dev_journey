// let obj={
//     a:7,
//     b:"Anurag"
// }
// console.log(obj)

// let animal={
//     eats:true
// };
// let rabbit={
//     jumps:true
// };
// rabbit.__proto__ =animal; //sets rabbit.[[prototype]]=animal

class Animal{
    constructor(name){
        this.name=name
        console.log("Object is created...")
    }
    eats(){
        console.log("Kha rha hu")
    }
    jumps(){
        console.log("Kood rha hu")
    }
}
class Lion extends Animal{
      
}
let a=new Animal("Lulla");
console.log(a)

let l=new Lion("Sher")
console.log(l)
