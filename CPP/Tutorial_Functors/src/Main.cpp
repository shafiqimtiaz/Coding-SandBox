#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Average {

private:
	double curr_avg;
	int curr_count;
public:
	Average() { curr_avg = 0; curr_count = 0; }

	int sum(int x[], int n) {
		int s = 0;
		for (int i = 0; i < n; i++) s += x[i];
		return s;
	}

	double operator()(int x[], int m) {
		int s = sum(x, m);
		curr_avg = (curr_count * curr_avg + s) / (m + curr_count);
		curr_count += m;
		return curr_avg;
	}

	double operator()(int x) {
		curr_avg = (curr_count * curr_avg + x) / (1 + curr_count);
		curr_count++;
		return curr_avg;
	}
};

template <typename T>
T add(T a, T b) {
	return a + b;
}

template <class T, class E>
E add(T a, E b) {
	return a + b;
}

double get_avg(const int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; ++i) s += arr[i];
	return s / n;
}

int main()
{
	/*int x[3] = { 1,2,3 };
	int y[1] = { 4 };
	int z[3] = { 5,6,7 };
	Average a;
	cout << a(x, 3) << " " << a(1) << " " << a(z, 3) << "\n";*/

	/*int x = 2;
	double y = 10.0;
	cout << add(x, x) << " " << add(x, y) << " " << add(string("Hello"), string("Mom")) << "\n";*/

	/*std::vector<int> v{ 1,2,3,4,5,6,7 };
	std::for_each(v.begin(), v.end(), [](int& value) { value *= 2; });
	std::for_each(v.begin(), v.end(), [&](int value) { v.push_back(value); });
	std::for_each(v.begin(), v.end(), [](int& value) { cout << value << " "; });*/

	int x[3] = { 1,2,3 };

	auto f1 = [=]() {
		//x[2] = 1000; doesnt work since capture is by value
		return get_avg(x, 3);
	};

	auto f2 = [&]() {
		x[2] = 1000; // works and can change the capture list elements
		return get_avg(x, 3);
	};

	auto f3 = []() {
		//x[2] = 1000;
		int x[3] = { 10,20,30 }; // cant work with external items, variables inside scope can be used
		return get_avg(x, 3);
	};

	cout << f1() << " " << f2() << " " << f3() << endl;

	return 0;
}