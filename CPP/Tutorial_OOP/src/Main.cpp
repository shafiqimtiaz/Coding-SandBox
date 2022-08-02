#include <iostream>
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

/*****************************************************/

class Foo
{
public:
	Foo() { cout << "Foo ctor\n"; }
	~Foo() { cout << "Foo dtor\n"; }
};

class Bar
{
public:
	Bar() { cout << "Bar ctor\n"; }
	~Bar() { cout << "Bar dtor\n"; }
};

class Base
{
	Foo f;
	int x;
public:
	Base() { cout << "Base ctor "; }
	Base(int xxx) : x{ xxx } { cout << "Base ctor x: " << x << '\n'; }
	~Base() { cout << "Base dtor\n"; }
};

class Der : public Base
{
	Bar b;
public:
	Der() { cout << "Der ctor\n"; }
	~Der() { cout << "Der dtor\n"; }
};

class Sub : public Base
{
	int y;
public:
	// initialization order does not matter
	Sub(int xx, int yy) : y{ yy }, Base(xx)	{
		cout << "Sub ctor y: " << y << '\n';
	}
	~Sub() { cout << "Sub dtor\n"; }
};

/*****************************************************/

struct Animal {
	Animal() { cout << "Animal()\n"; }
	~Animal() { cout << "~Animal()\n"; }
};

struct Mammal : public Animal {
	Mammal() { cout << "Mammal()\n"; }
	~Mammal() { cout << "~Mammal()\n"; }
};

struct Human : public Mammal {
	Human() { cout << "Human()\n"; }
	~Human() { cout << "~Human()\n"; }
};

/*****************************************************/

struct Fruit {
	explicit Fruit(const std::string& name)
	{
		cout << "Fruit( " << name << " )\n";
	}

};

struct Apple : public Fruit {
	Apple(const std::string& name) : Fruit(name)
	{
		cout << "Apple( " << name << " )\n";
	}

};

struct McIntosh : public Apple {
	McIntosh(const std::string& name = "McIntosh") : Apple(name)
	{
		cout << "McIntosh( " << name << " )\n";
	}

};
struct GrannySmith : public Apple {
	GrannySmith(const std::string& name = "Granny Smith") : Apple(name)
	{
		cout << "GrannySmith( " << name << " )\n";
	}

};

/*****************************************************/

class Employee {
	string name{ "an employee" };
public:
	Employee() { cout << "Employee Ctor\n"; }
	virtual ~Employee() { cout << "Employee Dtor\n"; }

	virtual void print() const;
	void print(char ch) const;

};

void Employee::print() const {
	cout << "\tname: " << name << endl;
}

void Employee::print(char ch) const {
	cout << "\tch: " << ch << '\n';
}

class Manager : public Employee {
	int rank{ 10 };
public:
	Manager() { cout << "Manager Ctor\n"; }
	virtual ~Manager() { cout << "Manager Dtor\n"; }

	virtual void print() const override; // redefinition of an Employee's member name:

}; // hides all Employee::print member functions

void Manager::print() const {
	Employee::print(); // the only way to access Employee::print()
	cout << "\tManager rank: " << rank << endl;
}

class Boss : public Employee {
	int salary{ 100000 };
public:
	Boss() { cout << "Boss Ctor\n"; }
	virtual ~Boss() { cout << "Boss Dtor\n"; }

	virtual void print() const override;
};

void Boss::print() const {
	Employee::print();
	cout << "\tBoss salary: " << salary << endl;
}

void show(Employee* pEmp) {
	cout << "show - Employee* pEmp\n";
	pEmp->print();
}

void show(Employee& rEmp) {
	cout << "show - Employee& rEmp\n";
	rEmp.print();
}

/*****************************************************/

struct Pet
{
	string name;
	size_t age;

	Pet(const string& name, const size_t& age)
		: name(name), age(age) {}

	virtual void print(ostream& out) const {
		out << "I'm " << name << ", a pet \n";
	}
};

struct Dog : public Pet
{
	string breed;

	Dog(const string& name, const size_t& age, const string& breed)
		: Pet(name, age), breed(breed) {}

	void print(ostream& out) const override {
		Pet::print(out);
		cout << "I'm " << name << ", a dog. Age " << age << " and Breed " << breed << "\n";
	}
};

struct Poodle : public Dog {
	Poodle(const string& name, const size_t& age, const string& breed = "Poodle")
		: Dog(name, age, breed) {}

	void print(ostream& out) const override {
		Dog::print(out);
		cout << "I'm " << name << ", a Poodle. Age " << age << " and Breed " << breed << "\n";
	}
};

ostream& operator<<(ostream& out, const Pet& pet) {
	pet.print(out);	// this call is polymorphic because:
					// (1) print() in Pet, the base class, is virtual
					// (2) pet is a refrence to Pet
	return out;
}

/*****************************************************/

int genRandom(int min, int max)
{
	// ensure min <= max
	if (min > max) std::swap(min, max);

	// define a distribution type and range
	std::uniform_int_distribution<int> dist(min, max);

	// define a uniformly-distributed integer random number generator
	// that produces non-deterministic random numbers. (see here)
	std::random_device gen;

	// generate and return a random integer in the range [min, max], inclusive
	return dist(gen);
}

int genRandomInt(int min, int max)
{
	static bool is_seeded{ false }; // is_seeded is a static local variable
		// initialized only on the very first call;
			// It is used here to ensure the random
			// number generator is seeded only once
	if (!is_seeded)
	{
		std::srand(std::time(0)); //use current time as seed for random generator
		is_seeded = true;
	}
	if (min > max) std::swap(min, max); // ensure min <= max
	int randomInt = std::rand() % (max - min + 1) + min;
	return randomInt; // return an int in the range [min, max], inclusive
}

/*****************************************************/

// WHAT IS OUTPUT ?

struct B {
	void f() { cout << "B::f\n"; } // non-virtual
	virtual void vf() { cout << "B::vf\n"; } // virtual
};

struct D : public B {
	void f() { cout << "D::f\n"; } // non-virtual, hides B::f
	void vf() override { cout << "D::vf\n"; } // virtual (why?)
};

void make_call_by_ptr(B* x) {
	x->f(); // compile-time binding
	x->vf(); // runtime binding
}

void make_call_by_ref(B& x) {
	x.f(); // compile-time binding
	x.vf(); // runtime binding
}

void make_call_by_val(B x) {
	x.f(); // compile-time binding
	x.vf(); // compile-time binding
}

/*****************************************************/



/*****************************************************/

int main()
{
	//Der d;

	/**************************/

	//Sub s{ 10, 5 };

	/**************************/

	//Animal a;
	//cout << "--------------\n";
	//Mammal m;
	//cout << "--------------\n";
	//Human h;
	//cout << "--------------\n";

	/**************************/

	//Employee emp;
	//cout << "--------------\n";
	//Manager mngr;
	//cout << "--------------\n";

	/**************************/

	//Employee emp;
	//cout << "--------------\n";
	//Employee* pEmp = new Employee;
	//cout << "--------------\n";
	//delete pEmp;
	//cout << "--------------\n";

	//Employee emp;
	//cout << "--------------\n";
	//Manager * pMngr = new Manager;
	//cout << "--------------\n";
	//delete pMngr;
	//cout << "--------------\n";

	//Employee emp;
	//cout << "--------------\n";
	//Employee* pEmp = new Manager;
	//cout << "--------------\n";
	//delete pEmp;
	//cout << "--------------\n";

	/**************************/

	//McIntosh m; // uses m's default name
	//GrannySmith g("Canadian Granny Smith");

	/**************************/

	//Manager m;
	//m.print();
	////m.print('a'); // error: print(char ch) of Employee hidden in Manager
	//m.Employee::print('a'); // the only way an object of Manager can acess a member of the
							// base class Employee whose name it has redefined

	//show(&m);
	//show(m);
	//Boss b; show(&b);
	//show(b);

	/**************************/

	//Pet pet_obj("Coco", 3);
	//cout << pet_obj.name << " " << pet_obj.age << '\n';

	//Dog dog("Duggee", 5, "Boxer");

	//pet_obj = dog;	// upcast base object = derived object
	//				// only the Pet part of dog is copied into pet_obj
	//				// the Dog part of dog is lost in the process

	//Pet& pet_ref = dog;	// upcast ok; base reference = derived object
	//Pet* pet_ptr = &dog;	// upcast ok; base pointer = address of derived object

	//cout << pet_obj.name << " " << pet_obj.age << '\n';
	//cout << pet_ref.name << " " << pet_ref.age << '\n';
	//cout << pet_ptr->name << " " << pet_ptr->age << '\n';

	////dog = pet_obj; // No operator= matches these operands: Dog = Pet

	Poodle oreo{ "Oreo",2 };
	cout << oreo << "\n";

	/**************************/

	//for (int i{}; i < 10; ++i) {
	//	cout << genRandom(1, 100) << "\n";
	//}

	/**************************/

	// WHAT IS OUTPUT ?

	//B b;
	//D d;

	//// polymorphic calls
	//B* basePtr = &b;
	//make_call_by_ptr(basePtr); // B::f, B::vf

	//basePtr = &d;
	//make_call_by_ptr(basePtr); // B::f, D::vf

	//// polymorphic calls
	//make_call_by_ref(b); // B::f, B::vf
	//make_call_by_ref(d); // B::f, D::vf

	//// regular calls
	//make_call_by_val(b); // B::f, B::vf
	//make_call_by_val(d); // B::f, B::vf // d loses the derived class data and gets upcasted to b

	/**************************/



	/**************************/

	return 0;
}