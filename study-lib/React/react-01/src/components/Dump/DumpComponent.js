import React from 'react'


export default function HelloWorld({...props}) {
  console.log('hello-world render');
    
  return (
    <div className='hello-world'>
      <h1>{props.title}</h1>
    </div>
  )
}