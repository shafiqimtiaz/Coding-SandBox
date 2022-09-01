import "./App.css";

function App() {
  return (
    <div className="App">
      <h1>Hello World</h1>
      <Person name="John" age="30" />
      <Person name="Mark" age="21" />
    </div>
  );
}

function Person(props) {
  return (
    <div className="Person">
      <h2>{props.name}</h2>
      <p>{props.age}</p>
    </div>
  );
}

export default App;
