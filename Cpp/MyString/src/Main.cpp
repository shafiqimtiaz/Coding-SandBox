#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;

class MyString
{
private:
	char* m_Buffer{ nullptr };
	size_t m_Size{ 0 };
public:
	MyString(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);

		m_Buffer[m_Size] = 0;
	}

	MyString(const MyString& other) : m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~MyString()
	{
		delete[] m_Buffer;
	}

	static void str_print(MyString& string)
	{
		cout << string << endl;
	}

	char& operator[] (size_t index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& output, const MyString& string);
};

std::ostream& operator<<(std::ostream& output, const MyString& string)
{
	output << string.m_Buffer;
	return output;
}

int main()
{
	MyString string1 = "Shafiq";
	MyString string2 = string1;

	string2[2] = 'o';

	MyString::str_print(string1);
	MyString::str_print(string2);
}