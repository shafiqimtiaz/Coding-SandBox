import React from "react";
import "./App.css";
import MainComponent from "./components/MainComponent";
import { BrowserRouter } from "react-router-dom";

class App extends React.Component {
	render() {
		return (
			<div className="App">
				<BrowserRouter>
					<MainComponent />
				</BrowserRouter>
			</div>
		);
	}
}

export default App;
