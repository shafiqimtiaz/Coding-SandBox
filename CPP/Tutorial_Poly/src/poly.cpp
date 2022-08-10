#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Animal {
private:
	string name;
	int age;
public:
	Animal(string name, int age) :name(name), age(age) {
		cout << "Animal Constructor" << endl;
	}
	virtual ~Animal() {
		cout << "Animal Destructor" << endl;
	}
	virtual void makeSound() const = 0;

	void toString() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}
};

class Dog : public Animal {
private:
	string color;
public:
	Dog(string name, int age, string color) :Animal(name, age), color(color)
	{
		cout << "Dog Constructor" << endl;
	}
	virtual ~Dog() { cout << "Dog Destructor" << endl; }

	virtual void makeSound() const override {
		cout << "Woooooooooof!" << endl;
	}
	void toString() {
		Animal::toString();
		cout << "color: " << color << endl;
	}

};


class Cat : public Animal {
private:
	int claws;
public:
	Cat(string name, int age, int claws)
		:Animal(name, age), claws(claws)
	{
		cout << "Cat Constructor" << endl;
	}

	virtual ~Cat() { cout << "Cat Destructor" << endl; }

	virtual void makeSound() const override {
		cout << "Meeeeeeeeeeeooow!" << endl;
	}

	void toString() {
		Animal::toString();
		cout << "claws: " << claws << endl;
	}

};


class Wolf : public Dog {
private:
	string eyeColor;
public:
	Wolf(string name, int age, string color, string ec)
		:Dog(name, age, color), eyeColor(ec)
	{
		cout << "Wolf Constructor" << endl;
	}

	virtual ~Wolf() { cout << "Wolf Destructor" << endl; }

	virtual void makeSound() const override {
		cout << "uuuuuuuuuuuuu!" << endl;
	}

	void toString() {
		Dog::toString();
		cout << "color: " << eyeColor << endl;
	}
};