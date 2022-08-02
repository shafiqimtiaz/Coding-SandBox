#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

#include "my_Array_iterator.h"

int main()
{
	clock_t tStart = clock();

	MyArray<double> dArray{ 5 };
	dArray[0] = 12.34;
	dArray[1] = 56.78;
	dArray[2] = 9.10;
	dArray[3] = 11.12;
	dArray[4] = 13.14;

	for (MyArray<double>::iterator it{ dArray.begin() }; it != dArray.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	std::vector<double> dVec;
	std::copy(dArray.begin(), dArray.end(), std::back_inserter(dVec));
	for (std::vector<double>::iterator it{ dVec.begin() }; it != dVec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// time calculation
	printf("\nTime taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	return 0;
}