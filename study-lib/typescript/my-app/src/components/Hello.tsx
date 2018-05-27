import * as React from 'react'

export interface Props {
  name: string;
  enthusiasmLevel?: number;
}

interface State {
  num: number;
}

// let a: any = null

class Hello extends React.Component<Props, {}> {
  public state: State = {
    num: 1
  }

  constructor(props: Props) {
    super(props)
  }

  public onChange = (e: any) => {
    const val = e.target.value
    console.log('s', encodeURIComponent(val))
    this.setState({num: e.target.value})
    // a = e.target
  }

  public render() {
    const { name, enthusiasmLevel = 1 } = this.props;
    if (enthusiasmLevel <= 0) {
      throw new Error('You could be a little more enthusiastic. :D');
    }

    return (
      <div className="hello">
        <div className="greeting">
          Hello {name + getExclamationMarks(enthusiasmLevel)}
          {this.state.num}
          <input type='text' name="name" onChange={this.onChange} />
        </div>
      </div>
    );
  }
  


}

export default Hello

function getExclamationMarks(numChars: number) {
  return Array(numChars + 1).join('!')
}