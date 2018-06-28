import React, { Component } from 'react';

export default class TickComponent extends Component {
  state = {
    tick: [],
  }
  onClick = () => {
    this.state.tick.push(1)
    this.setState({
      tick: this.state.tick
    })
  }

  render() {
    console.log('tick-component render');
    
    const {tick} = this.state
    return (
      <div>
        <h1>Component 点击了多少次：{tick.length}</h1> 
        <button onClick={this.onClick}>click me</button>
      </div>
    )
  }
}