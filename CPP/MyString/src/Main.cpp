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
		: length{ strlen(source) }, data{ new char[strlen(source) + 1] }
	{
		cout << "Created" << endl;
		//length = strlen(source);
		//data = new char[length + 1];
		strcpy(data, source);
	}

	MyString(const MyString& other)
		: length{ other.length }, data{ new char[other.length + 1] }
	{
		cout << "Copied" << endl;
		strcpy(data, other.data);
	}

	MyString(MyString&& other) noexcept
	{
		cout << "Moved" << endl;

		length = other.length;
		data = other.data;

		other.length = 0;
		other.data = nullptr;
	}

	~MyString()
	{
		cout << "Destroyed: " << *this << endl;
		delete[] data;
	}

	void print(ostream& sout) const
	{
		if (data != NULL && strlen(data) > 0) {
			sout << data;
		}
		else sout << "";
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

	Entity(MyString&& other) noexcept
		: name{ move(other) }
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
	{
		MyString s1 = "Copy Shafiq";
		Entity e1(s1);
		cout << "e1: " << e1 << endl;
		cout << "s1: " << s1 << endl;
	}
	cout << endl;
	{
		MyString s2 = "Move Shafiq";
		Entity e2(move(s2));
		cout << "e2: " << e2 << endl;
		cout << "s2: " << s2 << endl;
	}
	cout << endl;
}