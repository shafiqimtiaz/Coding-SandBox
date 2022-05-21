#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::move;

/************************************************************************/

class MyString
{
public:
	MyString() = default;

	MyString(const char* source)
		: data{new char[strlen(source) + 1]}, length{strlen(source)}
	{
		cout << "Created" << endl;
		strcpy(data, source);
	}

	MyString(const MyString& other)
		: data{ new char[other.length] + 1 }, length{other.length}
	{
		cout << "Copied" << endl;
		strcpy(data, other.data);
	}

	~MyString()
	{
		cout << "Destroyed" << endl;
		delete data;
	}

	void print(ostream& sout) const
	{
		sout << data;
	}

	friend ostream& operator<<(ostream& sout, const MyString& source);

private:
	char* data;
	size_t length;
};

ostream& operator<<(ostream& sout, const MyString& source)
{
	source.print(sout);
	return sout;
}

/************************************************************************/

class Entity
{
public:
	Entity(const MyString& source)
		: name{source}
	{
	}

	void printName(ostream& sout) const
	{
		name.print(sout);
	}

	friend ostream& operator<<(ostream& sout, const Entity& source);

private:
	MyString name;
};

ostream& operator<<(ostream& sout, const Entity& source)
{
	source.printName(sout);
	return sout;
}

/************************************************************************/

int main()
{
	//MyString name = "Shafiq";
	//MyString name2 = "Hoobla";
	//cout << name << " " << name2 << endl;

	Entity e(MyString("Shafiq"));
	//cout << e << endl;
}