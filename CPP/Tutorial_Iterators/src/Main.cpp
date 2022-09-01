#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "my_Array_iterator.h"

template<typename Container>
void print(const Container con)
{
	for (auto& val : con) cout << val << " ";
	cout << "\n";
}

template<typename iterator>
void printContainer(iterator start, iterator finish) {
	for (iterator it = start; it != finish; ++it) cout << *it << " ";
	cout << "\n";
}

class Squared_Number
{
private:
	int num{ 0 };
public:
	int operator()() {
		++num;
		return num * num;
	}
};

class Sum {
	int total{ 0 };
public:
	int getSum() const { return total; }
	void operator()(int x) { total += x; }
};

template<class T>
class LargerThan {
public:
	bool operator()(const T& obj1, const T& obj2) { return (obj1 > obj2); }
};

class AlternateSum
{
	int sign{ -1 };
public:
	AlternateSum() = default; // other special memebers defaulted as well
	int operator()(int a, int b)
	{
		sign = -sign;
		return a + (b * sign);
	}
};

int main()
{
	clock_t tStart = clock();

	/*MyArray<double> dArray{ 5 };
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
	cout << endl;*/

	/*std::vector<int> v1{ 10, 20, 30, 40, 50 };
	std::vector<int> v2{ 3, 5, 7 };

	std::copy(v1.begin() + 0, v1.begin() + 2, v2.begin());
	print(v2);
	std::copy(v1.begin() + 2, v1.begin() + 5, v2.begin());
	print(v2);*/

	std::vector<int> v3{ 11, 22, 33 };

	auto it = v3.begin(); // points to the first element
	++it; // point to 2nd vector element
	*it = 99; // modify the 2nd element

	auto it_inserter{ std::inserter(v3,it) };
	*it_inserter = 66;
	*it_inserter = 77;
	*it_inserter = 88;

	auto it_back_inserter{ std::back_inserter(v3) };
	*it_back_inserter = 1000;

	print(v3);

	cout << "-----------------------\n";

	std::list<int> mylist{};
	auto mylist_back_inserter{ std::back_inserter(mylist) };
	auto mylist_front_inserter{ std::front_inserter(mylist) };

	*mylist_front_inserter = 66;
	*mylist_front_inserter = 77;
	*mylist_back_inserter = 888;
	*mylist_front_inserter = 99;
	*mylist_back_inserter = 555;

	print(mylist); // 99 77 66 888 555

	std::vector<int> v4{ 11, 22, 33 };

	auto mylist_it{ mylist.begin() }; // mylist_it pointint at 99
	std::advance(mylist_it, 2); // mylist_it pointing at 66

	// insert v4 into mylist before 66
	std::copy(v4.begin(), v4.end(), std::inserter(mylist, mylist_it));
	print(mylist); // 99 77 11 22 33 66 888 555

	// insert v4 at the back of mylist
	std::copy(v4.begin(), v4.end(), std::back_inserter(mylist));
	print(mylist); // 99 77 11 22 33 66 888 555 11 22 33

	// insert v4 at the front of mylist
	std::copy(v4.begin(), v4.end(), std::front_inserter(mylist));
	print(mylist); // 33 22 11 99 77 11 22 33 66 888 555 11 22 33

	cout << "------------1-----------\n";

	std::vector<int> vec(10);
	//std::vector<int> vec{ 10 };

	//std::generate(vec.begin(), vec.end(), Squared_Number());

	Squared_Number sn{};
	std::generate(vec.begin(), vec.end(), sn);
	print(vec);

	cout << "------------2-----------\n";

	std::vector<int> v5{ 1, 2, 3, 4, 5 };
	Sum result = for_each(v5.begin(), v5.end(), Sum());
	//Sum s;
	//Sum result = for_each(v5.begin(), v5.end(), s);
	cout << "Sum is " << result.getSum() << endl;

	cout << "------------3-----------\n";

	std::vector<int> v6{ 1, 2, 3, 4, 5 };
	int total = std::accumulate(
		v6.begin(), // iterator to initial element, in the range
		v6.end(), // iterator to "end" element, not in the range
		0); // the initial value
	cout << "Accumulate is " << total << endl;

	cout << "------------4-----------\n";

	std::vector<int> intVec{ 1,2,3,4,5 };
	printContainer(intVec.begin(), intVec.end()); // 1 2 3 4 5
	printContainer(intVec.begin() + 1, intVec.end() - 1); // 2 3 4

	std::list<double> intList(5, 1.1);
	printContainer(std::next(intList.begin(), 2), std::prev(intList.end(), 2)); // 1.1 1.1 1.1 1.1 1.1
	//printContainer(std::advance(intList.begin(), 2), std::prev(intList.end(), 2)); // 1.1 1.1 1.1 1.1 1.1

	/*
	cout << "------------5-----------\n";

	cout << "Enter integers: ";
	std::istream_iterator<int> is_start(cin); // start of input stream
	std::istream_iterator<int> is_end; // end of input stream

	// create an output stream separated by a tab character
	std::ostream_iterator<int> os_start(cout, "\t");

	remove_copy(is_start, // start of input range
		is_end, // end of input range,
		os_start, // start of output range
		0); // objects to remove


	std::istream_iterator<int> iss(cin), eos;
	int m{ 10 };
	std::for_each(iss, eos, [m](int value) { cout << value * m << endl; });
	*/

	cout << "------------6-----------\n";

	int arr[10]{ 12, 21, 13, 31, 14, 41, 15, 51, 16, 61 };
	std::sort(arr, arr + 10, LargerThan<int>()); // sort array
	auto outArr = std::ostream_iterator<int>(cout, ", ");
	copy(arr, arr + 10, outArr); // print array
	cout << '\n';

	std::list<double> aList{ 1.2, 2.1, 1.3, 3.1, 1.4, 4.1, 1.5, 5.1, 1.6 };
	aList.sort(LargerThan<double>()); // sort list
	auto outList = std::ostream_iterator<double>(cout, ", ");
	copy(aList.begin(), aList.end(), outList); // print list
	cout << '\n';

	std::vector<char> aVec{ 'q', 'u', 'e', 's', 't' };
	auto outVec = std::ostream_iterator<char>(cout, ", ");
	std::sort(aVec.begin(), aVec.end(), LargerThan<char>()); // sort vector
	copy(aVec.begin(), aVec.end(), outVec); // print vector
	cout << '\n';

	cout << "------------7-----------\n";

	std::vector<int> v7{ 1, 2, 3, 4, 5 };
	int alternate_sum = std::accumulate(
		v7.begin(), // source start iterator
		v7.end(), // source end iterator
		0, // initial value
		AlternateSum() // action performed on each element
	);
	cout << "alternate sum: " << alternate_sum << '\n';

	cout << "------------8-----------\n";

	std::vector<int> v8{ 1, 2, 3, 4, 5 };
	int product = std::accumulate(
		v8.begin(), // source start iterator
		v8.end(), // source end iterator
		1, // initial value
		[](int a, int b) {return a * b; } // action performed on each element
	);
	cout << "product: " << product << '\n';

	cout << "------------9-----------\n";

	auto sum{ [](int a, int b) {return a + b; } };
	auto resultSeq = std::ostream_iterator<int>(cout, ", ");
	std::vector<int> v9{ 1, 2, 3, 4, 5 };
	std::list<int> lst{ 11, 22, 33, 44, 55, 48, 89 };

	std::transform(
		v9.begin(), // source 1 start
		v9.end(), // source 1 end
		lst.begin(), // source 2 start
		resultSeq, // destiniation start
		sum // action performed on each pair
	);

	cout << '\n';
	std::copy(v9.begin(), v9.end(), std::ostream_iterator<int>(cout, ", "));
	cout << '\n';
	std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(cout, ", "));
	cout << '\n';



	// time calculation
	printf("\nTime taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	return 0;
}