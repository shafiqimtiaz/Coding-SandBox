#include <iostream>
#include <map>
#include <array>
#include <list>
#include <forward_list>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

template <typename ForwardIt> // print the range [start, finish)
void printList(ForwardIt start, ForwardIt finish, std::string msg)
{
	cout << msg << ": ";
	for (auto it{ start }; it != finish; ++it) cout << *it << ' ';
	cout << endl;
}

template <class ForwardIt, class T>
void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value)
{
	for (; first != last; ++first) {
		if (*first == old_value) {
			*first = new_value;
		}
	}
}

template <class ForwardIt, class UnaryPredicate, class T>
void replace_if(ForwardIt first, ForwardIt last, UnaryPredicate p, const T& new_value)
{
	for (; first != last; ++first) {
		if (p(*first)) {
			*first = new_value;
		}
	}
}

void removeOddNumbers(std::list<int>& lst)
{ // remove the odd numbers in vec
	printList(lst.begin(), lst.end(), "original ");
	auto new_logical_end{
		std::remove_if(begin(lst), end(lst),
		[](int number) { return number % 2 == 1; })
	};
	printList(lst.begin(), lst.end(), "removed but messed up");
	printList(lst.begin(), new_logical_end, "removed using logical end");
	// Erase the range of numbers [new_logical_end, vec.end())
	lst.erase(new_logical_end, lst.end());
	printList(lst.begin(), lst.end(), "removed and erased");
}

class Point3D
{
	int x, y, z;
public:
	explicit Point3D(int x = 0, int y = 0, int z = 0)
		: x{ x }, y{ y }, z{ z } {}
	Point3D(const Point3D&) = default;
	Point3D& operator=(const Point3D&) = default;
	Point3D(Point3D&&) = default;
	Point3D& operator=(Point3D&&) = default;
	virtual ~Point3D() = default;

	friend ostream& operator<<(ostream& os, const Point3D&);
	friend istream& operator>> (istream& is, Point3D& point);
};
istream& operator>> (istream& sin, Point3D& point)
{
	sin >> point.x >> point.y >> point.z;
	return sin;
}
ostream& operator<<(ostream& os, const Point3D& point)
{
	os << '(' << point.x << ',' << point.y << ',' << point.z << ')';
	return os;
}

void printName(char initial, string name, int age) {
	char init = toupper(initial);
	cout << init << ". " << name << ", " << age << endl;
}

template <typename Container> // print any standard container
void print(Container con, std::string message) {
	cout << message << ": ";
	for (auto x : con) cout << x << ' '; cout << endl;
}

//
std::vector<int> merge(std::forward_list<int> flst1, std::forward_list<int> flst2)
{
	// the problem suggested in class assumed that the two lists are sorted
	// in ascending order (low to high)
	auto it1 = flst1.begin(); // equivalently, flst1.begin()
	auto it2 = flst2.begin();

	std::vector<int> mergedResult{}; // an empty vector; will store the result

	while (it1 != flst1.end() && it2 != flst2.end())
	{
		if (*it1 <= *it2) {
			mergedResult.push_back(*it1);
			++it1;
		}
		else {
			mergedResult.push_back(*it2);
			++it2;
		}
	}

	// here either flst1 or flst2 or both have been completely processed
	// in case flst1 has unprocessed elements
	while (it1 != flst1.end())
	{
		mergedResult.push_back(*it1);
		++it1;
	}
	// in case flst2 has unprocessed elements
	while (it2 != flst2.end())
	{
		mergedResult.push_back(*it2);
		++it2;
	}
	return mergedResult;
}

int main()
{
	//std::map<std::string, double> test_score;
	//std::map<std::string, double, std::greater<std::string>> test_score;

	std::map<std::string, double> test_score;
	test_score["Farah"] = 74.5;
	test_score["Bob"] = 74.5;
	test_score["Jasmin"] = 87.5;
	test_score["Adam"] = 91.0;
	test_score["Salah"] = 100.0;
	test_score["Huifen"] = 83.75;

	// old style
	cout << "Score > 80 (old style)\n";
	std::map<std::string, double>::iterator it;
	for (it = test_score.begin(); it != test_score.end(); ++it) {
		if (it->second >= 80.0) {
			std::cout << "name: " << it->first << "\t"
				<< "score: " << it->second << std::endl;
		}
	}

	cout << "------------------------\n";

	// C++20
	cout << "Score > 80 (new style)\n";
	for (auto& [name, score] : test_score) {
		if (score >= 80.0) {
			std::cout << "name: " << name << "\t"
				<< "score: " << score << std::endl;
		}
	}

	cout << "------------------------\n";

	// C++11
	for (const auto& elem : test_score) {
		std::cout << "name: " << elem.first << "\t"
			<< "score: " << elem.second << std::endl;
	}

	cout << "------------------------\n";


	//name = "Jane"; // error: cannot modify the key
	test_score["Jane"] = test_score["Bob"]; // Jane's score = Bob's score
	test_score.erase("Bob");
	// score = 95.0; // OK

// C++20
	for (const auto& [name, score] : test_score) {
		std::cout << "name: " << name << "\t"
			<< "score: " << score << std::endl;
	}

	cout << "------------------------\n";

	for (auto iter{ test_score.begin() }; iter != test_score.end(); )
	{
		if (iter->second == 100.0) {
			iter = test_score.erase(iter); // iter already advanced
		}
		else {
			++iter; // score is not 100.0, so advance iter
		}
	}

	for (const auto& [name, score] : test_score) {
		std::cout << "name: " << name << "\t"
			<< "score: " << score << std::endl;
	}

	/*
	cout << "------------------------\n";

	map<string, int> words1; // (word, frequency) pairs
	for (std::string word; cin >> word; )
		++words1[word];
	//for (const auto& aPair : words)
	// cout << aPair.first << ": " << aPair.second << '\n';
	for (const auto& [word, frequency] : words1)
		cout << word << ": " << frequency << '\n';

	cout << "------------Ass1------------\n";

	std::map<string, vector<int>> words2;
	int line{};
	for (std::string word; cin >> word; )
	{
		words2[word].push_back(++line);
	}
	for (const auto& [word, vec] : words2) {
		cout << word << ": ";
		for (auto number : vec) cout << number << ' ';
		cout << '\n';
	}
	cout << endl;
	*/

	cout << "------------------------\n";

	std::list<int> lst{}; // an empty doubly linked-list
	for (int k = 1; k <= 15; ++k) lst.push_back(k);
	removeOddNumbers(lst);
	/*
	cout << "------------------------\n";

	cout << "enter three integers: " << endl;
	// define the input stream to read from
	std::istream_iterator<Point3D> my_cin_begin{ cin };// performs the first read
	std::istream_iterator<Point3D> my_cin_end{}; // end of input stream

	Point3D point{ *my_cin_begin }; // fetch the first read, initializing point
	cout << point << endl; // print point
	cout << "enter another set of three integers: ";
	++my_cin_begin; // read the next input
	point = *my_cin_begin; // fetch the input just read
	cout << point << endl; // print point
	++my_cin_begin; // read the next input
	cout << "enter as many sets of three integers,"
		"enter CTRL_Z or CTRL_d to stop inputting: \n";

	// define the output stream to write to
	std::ostream_iterator<Point3D> out_stream(cout, "\n");
	std::copy(my_cin_begin, my_cin_end, out_stream);
	*/
	cout << "------------------------\n";

	using namespace std::placeholders;

	auto write{ std::bind(printName, _2, _1, _3) };
	auto show{ std::bind(printName, _1, _3, _2) };
	auto print_10{ std::bind(printName, _2, _1, 10) };
	auto print_A_10{ std::bind(printName, 'A', _1, 10) };

	write("Lopez", 'j', 53);
	show('S', 30, "Gomez");
	print_10("Kaji", 'R');
	print_A_10("Smith");
	printName('S', "Doe", 10);
	printName('b', "Happie", 21);

	cout << "------------------------\n";

	std::forward_list<int> flist{ 7, 3, 0, 5, 4, 7, 85, 92, 1, 80, 2 };
	std::replace(flist.begin(), flist.end(), 0, 11); // replace zeros with 11
	print(flist, "original");

	// version 1: turn the binary functor std::less<int>() into a anonymous unary functor
	std::replace_if(flist.begin(), flist.end(),
		std::bind(std::less<int>(), _1, 7), 77); // replace less than 7 with 77
	print(flist, "replaced 7 with 77");

	// version 2: turn the binary functor std::greater_equal<int>() into a named unary functor
	auto gt_or_eq_to_80 = std::bind(std::greater_equal<int>(), _1, 80);
	std::replace_if(flist.begin(), flist.end(), gt_or_eq_to_80, 99);
	print(flist, "replaced >= 80 with 99");

	// version 3: using lambda function
	std::replace_if(flist.begin(), flist.end(), [](int num) { return num > 90; }, 1000);
	print(flist, "replaced x > y");

	cout << "------------------------\n";

	std::forward_list<int> flist1{ 1,1,5,7,7,9 }; // alreay sorted
	std::forward_list<int> flist2{ 1,4,4,5,8,9,11 }; //alreay sorted
	std::vector<int> result{ merge(flist1, flist2) };
	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(cout, " "));

	cout << "\n------------------------\n";

	std::array arr{ 1,2,3,4,5,6 };
	print(arr, "trying array: ");
}