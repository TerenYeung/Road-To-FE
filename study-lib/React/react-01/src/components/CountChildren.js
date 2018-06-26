import React, { Component } from '../../../../../../../../Library/Caches/typescript/2.9/node_modules/@types/react';

export default class CountChildren extends Component {
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
    console.log(React.Children.toArray(children));
    
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