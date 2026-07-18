import { useEffect } from "react"
import React from 'react'

const Navbar = ({color}) => {
    useEffect(() => {
        alert("color was changed")
    }, [color])

    //cleanup function will show after navbar line is removed from app.jsx
    useEffect(() => {
    alert("Hey welcome this is the first render of app.jsx")
    return () => {
      alert("component was unmounted")
    }
  }, [])
    
  return (
    <div>
      I am a navbar of {color} color hahahaha!!!!
    </div>
  )
}

export default Navbar
