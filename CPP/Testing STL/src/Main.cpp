#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void pushBack(int newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else {
			/*Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;*/

			tail->next = newNode;
			tail = newNode;
		}
	}

	void swapLink(int val1, int val2)
	{
		Node* temp = head;
		int nodeCount = 0;

		while (temp != nullptr)
		{
			nodeCount++;
			temp = temp->next;
		}

		if (val1 < 1 || val1 > nodeCount || val2 < 1 || val2 > nodeCount)
		{
			cout << "swap values not found\n";
			return;
		}

		int pos1 = 1;
		int pos2 = 1;

		Node* prev1 = nullptr, * prev2 = nullptr, * node1 = nullptr, * node2 = nullptr;

		temp = head;
		while (temp->data != val1 && (pos1 <= nodeCount))
		{
			pos1++;
			temp = temp->next;
		}

		temp = head;
		while (temp->data != val2 && (pos2 <= nodeCount))
		{
			pos2++;
			temp = temp->next;
		}

		temp = head;
		int i = 1;
		while (temp != nullptr && (i <= nodeCount))
		{
			if (i == pos1 - 1) prev1 = temp;
			if (i == pos1) node1 = temp;

			if (i == pos2 - 1) prev2 = temp;
			if (i == pos2) node2 = temp;

			temp = temp->next;
			i++;
		}

		if (node1 != nullptr && node2 != nullptr)
		{
			if (prev1 != nullptr) prev1->next = node2;
			if (prev2 != nullptr) prev2->next = node1;

			cout << "Swapped Link\n";

			Node* val = node1->next;
			node1->next = node2->next;
			node2->next = val;

			if (prev1 == nullptr) head = node2;
			else if (prev2 == nullptr) head = node1;
		}
	}

	void swapData(int val1, int val2)
	{
		Node* temp = head;
		int nodeCount = 0;

		while (temp != nullptr)
		{
			nodeCount++;
			temp = temp->next;
		}

		if (val1 < 1 || val1 > nodeCount || val2 < 1 || val2 > nodeCount)
		{
			cout << "swap values not found\n";
			return;
		}

		Node* pos1 = head;
		Node* pos2 = head;

		while (pos1->data != val1)	pos1 = pos1->next;
		while (pos2->data != val2)	pos2 = pos2->next;

		cout << "Swapped Data\n";

		int val = pos1->data;
		pos1->data = pos2->data;
		pos2->data = val;
	}

	void reverse()
	{
		if (head != nullptr)
		{
			Node* prevNode = head;
			Node* currNode = head->next;
			head = head->next;

			prevNode->next = nullptr;

			cout << "Reverse\n";

			while (head != nullptr)
			{
				head = head->next;
				currNode->next = prevNode;

				prevNode = currNode;
				currNode = head;
			}

			head = prevNode;
		}
	}

	void print()
	{
		if (head == nullptr)  return;

		Node* curr = head;

		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
};



void string_to_int_and_print(string& str)
{
	vector<int> vec{};

	for (size_t i{}; i < str.length(); ++i)
	{
		vec.push_back(str[i] - '0'); // converts string to int
	}

	for (int& v : vec)
	{
		cout << v << " ";
	}
	cout << "\n";
}

void bubbleSort_and_print(string& str)
{
	string temp{ str };

	bool sorted{ false };

	while (!sorted)
	{
		sorted = true;
		for (size_t i{ 1 }; i < temp.length(); ++i)
		{
			if (temp[i - 1] > temp[i])
			{
				std::swap(temp[i], temp[i - 1]);
				sorted = false;
			}
		}
	}

	cout << temp;
}

bool check_if_starts_with(string& str, string& check)
{
	if (str.starts_with(check))
	{
		return true;
	}
	return false;
}

void compareOperation(string& str, string& check)
{
	// compare(offset, length, string obj)

	int result{ str.compare(10, check.length(), check) };

	if (result == 0)
		cout << "\"" << str << "\" contains \"" << check << "\" starting at index 10\n";
	else
		cout << "Strings didn't match ";
}

int main()
{
	/*LinkedList list;

	list.pushBack(1);
	list.pushBack(3);
	list.pushBack(2);
	list.pushBack(4);
	list.pushBack(5);
	list.pushBack(6);
	list.print();

	list.swapLink(3, 6);
	list.print();

	list.swapData(4, 1);
	list.print();

	list.reverse();
	list.print();*/


	string phrase{ "Hoobla is magical in his own ways!!" };

	//string phrase;
	//cin >> phrase;

	//string_to_int_and_print(phrase);

	//cout << phrase.substr(4, 10) << "\n";
	//cout << phrase.substr(4) << "\n";

	//bubbleSort_and_print(phrase);

	string check{ "magical" };
	//cout << check_if_starts_with(phrase, check);

	compareOperation(phrase, check);



	return 0;
}