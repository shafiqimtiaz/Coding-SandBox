#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class Vector {
public:
	T arr[10];
	int used{ 0 };

	void push_back(T t) {
		arr[used++] = t;
	}

	void print() {
		for (int i = 0; i < used; i++) cout << arr[i] << endl;
	}
};


class Average {
private:
	double current_avg;
	int current_count;

public:
	Average() { current_avg = 0; current_count = 0; }
	int sum(int x[], int n) {
		int s = 0;
		for (int i = 0; i < n; i++) s += x[i];
		return s;
	}

	double operator() (int x[], int m) {
		int s = sum(x, m);
		current_avg = (current_count * current_avg + s) / (m + current_count);

		current_count += m;
		return current_avg;
	}

	double operator()(int x) {
		current_avg = (current_count * current_avg + x) / (1 + current_count);
		current_count++;
		return current_avg;
	}

};

template <class T>
T add(T a, T b) {
	return a + b;
}


//double get_average(const int arr[], int n) {
//	int s = 0;
//	for (int i = 0; i < n; i++) { s += arr[i]; }
//
//	return s / n;
//}