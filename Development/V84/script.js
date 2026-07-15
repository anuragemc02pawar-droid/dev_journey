console.log('Starting with Javascript')

async function getSongs() {
    let a = await fetch("http://127.0.0.1:3000/songs/")
    let response = await a.text();
    console.log(response)
    let div = document.createElement("div")
    div.innerHTML = response;
    let as = div.getElementsByTagName("a")

    let songs = []

    for (let index = 0; index < as.length; index++) {
        const element = as[index];
        if (element.href.endsWith(".mp3")) {
            songs.push(element.href)
        }
    }
    return songs
}


async function main() {
    //get the list of all songs
    let songs = await getSongs()


    document.querySelector(".songtime").innerHTML = "00:00 : 00:00"

    function formatTime(seconds) {
        if (isNaN(seconds)) return "00:00";

        let mins = Math.floor(seconds / 60);
        let secs = Math.floor(seconds % 60);

        return `${String(mins).padStart(2, "0")}:${String(secs).padStart(2, "0")}`;
    }
    console.log(songs)
    document.querySelector(".UdiUdi")
    //play the first song
    let playsong = document.querySelector(".playsong")

    let currSong = new Audio()
    document.querySelector(".UdiUdi")
        .addEventListener("click", () => {
            currSong.src = songs[0]
            currSong.play()
            playsong.src = "pause.svg"
            document.querySelector(".songinfo").innerHTML = `
<img src="https://i.scdn.co/image/ab67616d00001e0221d6e1053df28c5a33208c1a">
<div class="songdetails">
    <div class="songname">Udi Udi</div>
    <div class="artistline">
        <a href="" class="artist">Aneesh</a>,
        <a href="" class="artist">Sarkar</a>,
        <a href="" class="artist">Hruday</a>
    </div>
</div>`
            // document.querySelector(".songinfo").innerHTML= `<img src="https://i.scdn.co/image/ab67616d00001e0221d6e1053df28c5a33208c1a""> 
            // <span>Udi Udi</span>`
        })
    document.querySelector(".Aarzu")
        .addEventListener("click", () => {
            currSong.src = songs[1]
            currSong.play()
            playsong.src = "pause.svg"
            document.querySelector(".songinfo").innerHTML = `
<img src="https://i.scdn.co/image/ab67616d00001e020c28f02f30c669201ac4471d">
<div class="songdetails">
    <div class="songname">Udi Udi</div>
    <div class="artistline">
        <a href="#" class="artist">Noor</a>,
        <a href="#" class="artist">Khan</a>,
        <a href="#" class="artist">Madhurxo</a>
    </div>
</div>`
        })
    document.querySelector(".PalPal")
        .addEventListener("click", () => {
            currSong.src = songs[2]
            currSong.play()
            playsong.src = "pause.svg"
            document.querySelector(".songinfo").innerHTML = `
<img src="https://i.scdn.co/image/ab67616d00001e02236d0c72c9c3cbbfa15dd208">
<div class="songdetails">
    <div class="songname">Udi Udi</div>
    <div class="artistline">
        <a href="#" class="artist">Afusic</a>,
        <a href="#" class="artist">Talwiinder</a>,
        <a href="#" class="artist">AliSoomroMusic</a>
    </div>
</div>`
        })
    document.querySelector(".Chunari")
        .addEventListener("click", () => {
            currSong.src = songs[3]
            currSong.play()
            playsong.src = "pause.svg"
            document.querySelector(".songinfo").innerHTML = `
<img src="https://i.scdn.co/image/ab67616d00001e027423d9578263dad537a61a22">
<div class="songdetails">
    <div class="songname">Udi Udi</div>
    <div class="artistline">
        <a href="#" class="artist">Akshay & IP</a>,
        <a href="#" class="artist">Jonita Gandhi</a>,
        <a href="#" class="artist">Asees...</a>
    </div>
</div>`
        })
    document.querySelector(".BoomShaka")
        .addEventListener("click", () => {
            currSong.src = songs[4]
            currSong.play()
            playsong.src = "pause.svg"
            document.querySelector(".songinfo").innerHTML = `
<img src="https://i.scdn.co/image/ab67616d00001e0213dcb5da9470852eb67f1783">
<div class="songdetails">
    <div class="songname">Udi Udi</div>
    <div class="artistline">
        <a href="#" class="artist">KR$NA</a>,
        <a href="#" class="artist">Dhanda Nyoliwala</a>
    </div>
</div>`
        })

    playsong.addEventListener("click", () => {
        if (currSong.paused) {
            currSong.play()
            playsong.src = "pause.svg"
        } else {
            currSong.pause()
            playsong.src = "play.svg"
        }
    })

    currSong.addEventListener("timeupdate", () => {
        console.log(currSong.currentTime, currSong.duration)
        document.querySelector(".songtime").innerHTML = `${formatTime(currSong.currentTime)}:${formatTime(currSong.duration)}`
        document.querySelector(".circle").style.left=(currSong.currentTime/currSong.duration)*100 +"%"
    })

    document.querySelector(".seekbar").addEventListener("click", e=>{
        let percent = (e.offsetX/e.target.getBoundingClientRect().width)*100
        document.querySelector(".circle").style.left= percent + "%"
        currSong.currentTime=((currSong.duration)*percent)/100
    })

}
main()

