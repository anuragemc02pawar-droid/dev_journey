async function getData() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(445)
        }, 3500);
    })
}
async function main() {
    console.log("Loading modules")
    console.log("Do something else")
    console.log("Load Data")
    let data = await getData()
    console.log(data)
    console.log("Process Data")
    console.log("Task 2")
}
main()
// data.then((v)=>{
//     console.log(data)

// console.log("Process Data")
// console.log("Task 2")
// })