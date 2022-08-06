#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::vector;


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


	for (auto& [name, score] : test_score) {
		//name = "Jane"; // error: cannot modify the key
		test_score["Jane"] = test_score["Bob"]; // Jane's score = Bob's score
		test_score.erase("Bob");
		// score = 95.0; // OK
	}

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
	cout << endl;*/
}