// import * as React from 'react'
// import * as enzyme from 'enzyme'
// import Hello from './Hello'
// import * as Adapter from 'enzyme-adapter-react-16'

// enzyme.configure({ adapter: new Adapter() });

// it('renders the correct text when no enthusiasm level is given', () => {
//   const hello = enzyme.shallow(<Hello name='Teren' />)
//   expect(hello.find('.greeting').text()).toEqual('Hello Teren!')
// })

// it('renders the correct text with an explicit enthusiasm level of 1', () => {
//   const hello = enzyme.shallow(<Hello name='Teren' enthusiasmLevel={1} />)
//   expect(hello.find('.greeting').text()).toEqual('Hello Teren!')
// })

// it('renders the correct text with an explicit enthusiasm level of 5', () => {
//   const hello = enzyme.shallow(<Hello name='Teren' enthusiasmLevel={5} />)
//   expect(hello.find('.greeting').text()).toEqual('Hello Teren!!!!!')
// })

// it('throws error when the enthusiasm level is 0', () => {
//   expect(() => {
//     enzyme.shallow(<Hello name='Teren' enthusiasmLevel={0} />)
//   }).toThrow()
// })

// it('throws when the enthusiasm level is negative', () => {
//   expect(() => {
//     enzyme.shallow(<Hello name='Teren' enthusiasmLevel={-1} />);
//   }).toThrow();
// });