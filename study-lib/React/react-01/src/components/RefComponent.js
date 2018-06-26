import React, { Component } from '../../../../../../../../Library/Caches/typescript/2.9/node_modules/@types/react';

const FancyButton = React.forwardRef((props, ref) => (
  <button ref={ref} className="FancyButton" onClick={props.onClick}>{props.children}</button>
))

export default class RefComponent extends Component {
  constructor(props) {
    super(props)
    
    this.inputRef = React.createRef()
    this.childRef = React.createRef()
  }

  componentDidMount = () => {
    console.log(this.inputRef.current);
    console.log(React.isValidElement(this.inputRef));
    
    this.inputRef.current.focus()
  }

  handleClick = () => {
    console.log(this.childRef.current);
    
  }

  render() {
    return (
      <div>
        <input type="text" ref={this.inputRef} />
        <FancyButton onClick={this.handleClick} ref={this.childRef}>Click Me!</FancyButton>
      </div>
    )
    // return <input type="text" ref={input => this.inputRef = input} />
  }
}