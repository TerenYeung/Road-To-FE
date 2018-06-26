import React, { Component } from 'react'
import withMoize from '../components/HOC/withMoize'

@withMoize
export const HelloWorld = ({...props}) => {
  return (
    <div className='hello-world'>
      <h1>{props.title}</h1>
    </div>
  )
}