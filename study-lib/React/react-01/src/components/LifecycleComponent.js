import React, { PureComponent } from '../../../../../../../../Library/Caches/typescript/2.9/node_modules/@types/react'

export default class LifecycleComponent extends PureComponent {
  state = {
    timer: 0,
    time: 0,
    count: 0,
  }

  componentDidMount = () => {
    this.initTime()
  }

  componentWillUnmount() {
    clearInterval(this.state.timer)
  }

  shouldComponentUpdate(nextProps, nextState) {
    console.log(nextState)
    
    if (nextState.time !== this.state.time) return false
    return true
  }

  initTime = () => {
    let _ = this
    let timer = setInterval(() => {
      _.setState({
        time: new Date().toLocaleString(),
      })
    }, 1000)

    this.setState({
      timer,
    })
  }

  onClick = () => {
    this.setState({
      count: ++this.state.count,
    })
  }

  render() {
    return (
      <div className="lifecycle-component">
        <h1>{this.state.time}</h1>
        <button onClick={this.onClick}>click {this.state.count}</button>
      </div>
    )
  }
}