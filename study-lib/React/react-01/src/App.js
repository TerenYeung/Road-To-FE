import React, { Component } from '../../../../../../../Library/Caches/typescript/2.9/node_modules/@types/react';
import './App.css';
import TickPureComponent from './components/TickPureComponent'
import TickComponent from './components/TickComponent'
import CountChildren from './components/CountChildren'
import RefComponent from './components/RefComponent'
import LifecycleComponent from './components/LifecycleComponent'
import DumpComponent from './components/DumpComponent'

class App extends Component {
  render() {
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
        <DumpComponent title={'hello world'} />
      </div>
    )
  }
}

export default App;
