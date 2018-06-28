import React, { Component, PureComponent } from 'react';

export default class CountChildren extends PureComponent {
  state = {
    num: 0,
  }

  showChildren = () => {
    this.setState({
      num: React.Children.count(this.props.children)
    })
  }

  render() {
    const {children} = this.props
    console.log('count-children render');
    
    return (
      <div onClick={this.showChildren}>
        {children}
        <h2>{this.state.num}</h2>
        {
          React.Children.map(children, (child, i) => {
            return i > 2 && child
          })
        }
      </div>
    )
  }
}