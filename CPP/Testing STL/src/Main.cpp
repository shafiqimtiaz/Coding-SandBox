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
			tail->next = newNode;
			tail = newNode;
		}
	}

	void pushFront(int newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
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
			Node* prev = nullptr, * curr = nullptr, * nxt = nullptr;

			curr = head;

			while (curr != nullptr)
			{
				nxt = curr->next;
				curr->next = prev;
				prev = curr;
				curr = nxt;
			}
			head = prev;
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


int main()
{
	//LinkedList list;

	//list.pushBack(1);
	//list.pushBack(2);
	//list.pushBack(3);
	//list.pushBack(4);
	//list.pushBack(5);
	//list.pushBack(6);
	//list.print();

	// list.swapLink(3, 6);
	// list.print();

	// list.swapData(4, 1);
	// list.print();

	//list.reverse();
	//list.print();

	//list.pushFront(10);
	//list.pushFront(30);
	//list.pushFront(20);
	//list.pushFront(40);
	//list.pushFront(50);
	//list.pushFront(60);
	//list.print();


	// raw pointer LinkedList

	Node* head = nullptr;
	Node* tail = nullptr;

	Node* node1 = new Node();
	node1->data = 1;

	Node* node2 = new Node();
	node2->data = 2;

	Node* node3 = new Node();
	node3->data = 3;

	Node* node4 = new Node();
	node4->data = 4;

	Node* node5 = new Node();
	node5->data = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = nullptr;

	head = node1;
	tail = node5;

	// manual swap
	node2->next = node4;
	node4->next = node3;
	node3->next = node5;

	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}

	return 0;
}