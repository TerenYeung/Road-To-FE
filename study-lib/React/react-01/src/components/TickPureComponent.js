import React, { PureComponent } from 'react';

export default class TickPureComponent extends PureComponent {
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
    console.log('pure-component render');
    
    const {tick} = this.state
    return (
      <div>
        <h1>PureComponent 点击了多少次：{tick.length}</h1> 
        <button onClick={this.onClick}>click me</button>
      </div>
    )
  }
}