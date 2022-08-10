#include "poly.cpp"
#include "entity.cpp"
#include "functor.cpp"

int Mesh::id = 1;

void functor()
{
	int x[3] = { 1,2,3 };
	int y = 4;
	int z[3] = { 5,6,7 };
	Average a;
	cout << a(x, 3) << endl;
	cout << a(y) << endl;
	cout << a(z, 3) << endl;
	string str1{ "hello" }, str2{ " world" };
	cout << add(2, 3) << endl;
	cout << add(2.0, 3.0) << endl;
	cout << add(str1, str2) << endl;

	Vector<int> v;
	v.push_back(1);
	v.print();
	v.push_back(2);
	v.print();
	v.push_back(3);
	v.print();

	vector<int> v1{ 1,2,3,4,5 };
	for_each(v1.begin(), v1.end(),
		[](int& value) { value *= 2; });
	for_each(v1.begin(), v1.end(),
		[](int value) { cout << value << " "; });
	cout << "\n";
	int i = 0;
	//auto f1 = [=]() { get_average(x, 3); };
	auto f2 = [&]() { i = i + 1; return i; };
	//auto f3 = []() { int x[5] = { 1,2,3,4,5 }; get_average(x, 3); };
	cout << f2() << endl;
}

void entity()
{
	Entity e{ "ball" };
	Mesh m1{ "iron" };
	Mesh m2{ "water" };
	m1.Move(1, 3);
	m2.Move(2, 3);
	e.printData();
	m1.printData();
	m2.printData();
	RectangleMesh rm{ 1,2 };
	rm.printData();
	rm.doSomething();
}


void poly()
{
	vector<Animal*> animals = {
		new Cat("jack",10,3),
		new Dog("bob",4,"brown"),
		new Wolf("wolfy", 6, "gray", "green")
	};

	for (int i = 0; i < 3; i++) {
		animals.at(i)->makeSound();
	}

	for (int i = 0; i < 3; i++) {
		cout << typeid(animals.at(i)).name() << endl;
		cout << typeid(*(animals.at(i))).name() << endl;
		delete animals.at(i);
	}

}

int main() {

	functor();
	cout << "-----------------------------\n";
	entity();
	cout << "-----------------------------\n";
	poly();

	return 0;
}