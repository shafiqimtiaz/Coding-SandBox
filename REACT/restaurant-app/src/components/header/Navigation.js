import React, { Component } from "react";
import {
	Container,
	Navbar,
	NavbarBrand,
	Nav,
	NavItem,
	NavbarToggler,
	Collapse,
	NavLink,
} from "reactstrap";
import { Link } from "react-router-dom";

class Navigation extends Component {
	constructor(props) {
		super(props);
		this.state = {
			isNavOpen: false,
		};
	}

	navToggle = () => {
		this.setState({
			isNavOpen: !this.state.isNavOpen,
		});
	};

	render() {
		return (
			<div>
				<Navbar dark color="dark" expand="sm">
					<Container>
						<NavbarBrand href="/">Amar Restaurant</NavbarBrand>
						<NavbarToggler onClick={this.navToggle} />
						<Collapse isOpen={this.state.isNavOpen} navbar>
							<Nav className="ml-auto" navbar>
								<NavItem>
									<Link to="/" className="nav-link active">
										Home
									</Link>
								</NavItem>
								<NavItem>
									<Link to="/menu" className="nav-link">
										Menu
									</Link>
								</NavItem>
								<NavItem>
									<Link to="/about" className="nav-link">
										About
									</Link>
								</NavItem>
								<NavItem>
									<Link to="/contact" className="nav-link">
										Contact
									</Link>
								</NavItem>
								<NavLink href="https://shafiqimtiaz.github.io/">Github</NavLink>
							</Nav>
						</Collapse>
					</Container>
				</Navbar>
			</div>
		);
	}
}

export default Navigation;
