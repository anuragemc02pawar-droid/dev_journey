import React from 'react'
import "./Card.css"
const Card = (props) => {
  return (
    <div className='card' style={{overflow:"hidden"}}>
        <img src="https://imgs.search.brave.com/UOQRJv2hd_oz2dCk7BvwIDGq9ClX5EACWuMkJASdekg/rs:fit:500:0:1:0/g:ce/aHR0cHM6Ly9tZWRp/YS5pc3RvY2twaG90/by5jb20vaWQvNTEz/NTQ0MDE4L3ZlY3Rv/ci95b3VuZy1wcm9n/cmFtbWVyLWNvZGlu/Zy1hLW5ldy1wcm9q/ZWN0LmpwZz9zPTYx/Mng2MTImdz0wJms9/MjAmYz1TUlhtRU11/bEZ3TlQybFpFT0Z1/bUZ5REEtcjg4MjBi/NUJGZEpNY1VpYW9Z/PQ" alt="" width={350} height={220}/>
      <h1 style={{textAlign:'center'}}>{props.title}</h1>
      <p>{props.description}</p>
    </div>
  )
}

export default Card 
