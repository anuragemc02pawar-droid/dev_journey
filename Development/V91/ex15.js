const fs=require("fs");
const path =require("path");

let dirPath="./test";

let files=fs.readdirSync(dirPath)

console.log(files)

files.forEach((file)=>{
    let sourcePath=path.join(dirPath,file);
    if (!fs.statSync(sourcePath).isFile()){
        return;
    }
    
    let ext=path.extname(file).slice(1)
    if(ext===""){
        return;
    }
    console.log(ext)
    let folderPath =path.join(dirPath,ext);
    console.log(folderPath);
    if(!fs.existsSync(folderPath)){
        fs.mkdirSync(folderPath);
    }

    let destinationPath=path.join(folderPath,file);
    fs.renameSync(sourcePath,destinationPath);

    
})   
