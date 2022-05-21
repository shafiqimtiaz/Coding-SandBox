#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;

class MyString2
{
private:
	char* m_Buffer{ nullptr };
	size_t m_Size{ 0 };
public:
	MyString2(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);

		m_Buffer[m_Size] = 0;
	}

	MyString2(const MyString2& other) : m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~MyString2()
	{
		delete[] m_Buffer;
	}

	static void str_print(MyString2& string)
	{
		cout << string << endl;
	}

	char& operator[] (size_t index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& output, const MyString2& string);
};

std::ostream& operator<<(std::ostream& output, const MyString2& string)
{
	output << string.m_Buffer;
	return output;
}

int main()
{
	MyString2 string1 = "Shafiq";
	MyString2 string2 = string1;

	string2[2] = 'o';

	MyString2::str_print(string1);
	MyString2::str_print(string2);
}