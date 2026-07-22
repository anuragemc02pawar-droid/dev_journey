import { useState } from 'react'
import './App.css'
import { useForm } from "react-hook-form"

//install react hook form library


function App() {
  const {
    register,
    handleSubmit,
    watch,
    setError,
    formState: { errors,isSubmitting },
  } = useForm()

  const delay = (d)=>{
    return new Promise((resolve, reject)=>{
      setTimeout(() => {
        resolve()
      }, d*1000);
    })
  }

  const onSubmit= async (data) => {
    // await delay(2)                  //simulating network delay

    let r= await fetch("http://localhost:3000/", {method:"POST",headers: {
    "Content-Type": "application/json"
  }, body:JSON.stringify(data)})             //header content type is important to know it is json
    let res = await r.text()
    console.log(data,res)      // there will be an error coz can't match both ports 5173 and 3000 so import npm i cors (from npm cors)
    if(data.username === "lund" ||
       data.username === "loda" ||
       data.username === "chut" ||
       data.username === "gaand"){
      setError("myform", {message:"Your username violates our policy"})
    }
    if(data.password==="msdhoni07"){
setError("dhoni",{message:"Sacred Password"})
    }
    
  }

  return (
    <>
    {isSubmitting && <div>Submitting...</div>}
      <div className="container">
        <form action="" onSubmit={handleSubmit(onSubmit)}>
          <input placeholder='username' {...register("username", { required: {value:true,message:"This field is required"}, minLength:{value:3,message:"Username must have atleast 3 characters"}, maxLength:{value:10,message:"Username cannot exceed 10 characters"} })} type="text" />
          {errors.username && <div className='red'>{errors.username.message}</div>}
          <br />
          <input placeholder='password' {...register("password", {required:{value:true,message:"This is a required field"},minLength:{value:8,message:"Password must have atleast 8 characters"}, maxLength:{value:16,message:"Password cannot exceed 16 characters"} })} type="password"/>
          {errors.password && <div className='red'>{errors.password.message}</div>}
          <br />
          <input disabled={isSubmitting} type="submit" value="Submit" />
          {errors.myform && <div className='red'>{errors.myform.message}</div>}
          {errors.dhoni && <div className='red'>{errors.dhoni.message}</div>}
        </form>
      </div>
    </>
  )
}

export default App
