import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import heroImg from './assets/hero.png'
import './App.css'

function App() {
  const [count, setCount] = useState(0)
  // const [name, setName] = useState("Anurag")
  const [form, setForm] = useState({email: "", phone: ""})

  const handleClick = () => {
    alert("I am clicked")
  }
  const handleMouseOver = () => {
    alert("I am a mouse over")
  }
  const handleChange =(e)=> {
    // setName(e.target.value)
    setForm({...form,[e.target.name]:e.target.value})
  }

  return (
    <>
      <div className="button">
        <button onClick={handleClick}>Click Me🤭</button>
      </div>
      <div className="red" onMouseOver={handleMouseOver}>
        I am a red div
      </div>

      <input type="text" name='email' value={form.email} onChange={handleChange}/>
      <input type="text" name='phone' value={form.phone} onChange={handleChange}/>
    </>
  )
}

export default App
