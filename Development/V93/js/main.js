import fs, { readdir } from "fs/promises"
import fsn, { mkdir } from "fs"
import path from "path"

const basePath ="D:\\Development\\V93"

let files = await readdir(basePath)

for (const item of files) {
    console.log("running for...", item)
    let ext = item.split(".")[item.split(".").length-1]
    if(ext!="js" && ext!="json" && item.split(".").length>1){
        
    }
    if(fsn.existsSync(path.join(basePath,ext))){
        //move the file to this directory only if its not a js or json file
        fs.rename(path.join(basePath,item),path.join(basePath,ext,item))
    }else{
        fs.mkdir(ext)
        }
    console.log(item)
}