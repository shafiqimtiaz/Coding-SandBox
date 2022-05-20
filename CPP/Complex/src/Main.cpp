#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Complex
{
private:
	int x, y;
public:
	Complex() = delete;

	Complex(int real, int image) : x(real), y(image) {}

	Complex(const Complex& source)
		: Complex{ source.x, source.y }
	{
		cout << "Copy ctor" << endl;
	}

	Complex(Complex&& source)
		: x{ source.x }, y{ source.y }
	{
		cout << "Move ctor" << endl;
		source.x = 0;
		source.y = 0;
	}

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}

	void setX(int x)
	{
		this->x = x;
	}

	void setY(int y)
	{
		this->y = y;
	}
};

int main()
{
	int real, image;

	cout << "First number" << endl;
	cout << "Real: ";
	cin >> real;
	cout << "Imaginery: ";
	cin >> image;

	Complex num1(real, image);
	Complex num2 = num1;
	
	vector<Complex> v;

	v.push_back(Complex{ 1,2 });

	cout << "The sume of real parts: " << num1.getX() + num2.getX() << endl;
	cout << "The sume of image parts: " << num1.getY() + num2.getY() << endl;
}

