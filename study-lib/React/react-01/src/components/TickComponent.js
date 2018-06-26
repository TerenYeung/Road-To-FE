import React, { Component } from '../../../../../../../../Library/Caches/typescript/2.9/node_modules/@types/react';

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
    console.log('Component');
    
    const {tick} = this.state
    return (
      <div>
        <h1>Component 点击了多少次：{tick.length}</h1> 
        <button onClick={this.onClick}>click me</button>
      </div>
    )
  }
}