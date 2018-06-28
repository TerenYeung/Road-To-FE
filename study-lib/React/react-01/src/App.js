import React, { Component } from 'react';
import './App.css';
import TickPureComponent from './components/TickPureComponent'
import TickComponent from './components/TickComponent'
import CountChildren from './components/CountChildren'
import RefComponent from './components/RefComponent'
import LifecycleComponent from './components/LifecycleComponent'
import DumpComponent from './components/Dump/DumpComponent'
import {withMoize} from './components/HOC/withMoize'

class App extends Component {
  state = {
    count: 0,
  }

  handleClick = () => {
    this.setState({
      count: ++this.state.count
    })
  }

  render() {
    console.log('app render');
    
    return (
      <div>
        <TickComponent />
        {
          React.cloneElement(
            <TickComponent />,
          )
        }
        {
          React.createFactory(TickPureComponent)()
        }
        <TickPureComponent />
        {
          React.isValidElement(<TickPureComponent />) && 'True'
        }
        <CountChildren>
          <p>1</p>
          <p>2</p>
          <p>3</p>
          <p>4</p>
          <p>5</p>
        </CountChildren>
        <React.Fragment>
          hello world
          <h2>HHHAAA</h2>
        </React.Fragment>
        <RefComponent />
        <LifecycleComponent />
        {
          withMoize(<DumpComponent title={`'hello world '${this.state.count}`} />)
        }
        <DumpComponent title={`'hello world '${this.state.count}`} />
        <button onClick={this.handleClick}>click me</button>
      </div>
    )
  }
}

export default App;
