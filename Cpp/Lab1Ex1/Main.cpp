#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Imagin
{
private:
	double x, y;
public:
	Imagin(double real, double image) : x(real), y(image) {}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}
};

int main()
{
	double real, image;

	cout << "First number" << endl;
	cout << "Real: ";
	cin >> real;
	cout << "Imaginery: ";
	cin >> image;

	Imagin num1(real, image);

	cout << "Second number" << endl;
	cout << "Real: ";
	cin >> real;
	cout << "Imaginery: ";
	cin >> image;

	Imagin num2(real, image);

	cout << "The sume of real parts: " << num1.getX() + num2.getX() << endl;
	cout << "The sume of image parts: " << num1.getY() + num2.getY() << endl;

}

