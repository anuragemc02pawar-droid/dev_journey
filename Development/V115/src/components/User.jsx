import React from 'react'
import { useParams } from 'react-router-dom'

//dynamic routing

const User = () => {
    const params= useParams()
  return (
    <div>
      I am the user {params.username}
    </div>
  )
}

export default User
