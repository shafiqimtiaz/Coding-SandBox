#ifndef SLIST_H
#define SLIST_H

#include <iostream>
using std::ostream;

// Later on in the course, we will generalize DataType
// to stand for any type within the SList class below.
using DataType = int;

/*
* Encapsulates a singly linked list.
* Maintans the list through only a pointer to the first node in the list.
* Also maintains the number of nodes (the size) of the list.
* Defines the nodes in the list using a private data type member named Node.
*/
class SList
{
private:
	struct Node
	{
		Node(DataType data, Node* next)
			: data{ data }, next{ next } {}
		DataType data;
		Node* next;
	}; // although Node is private, its members are by default public within SList
	int theSize; // number of nodes in this SList
	Node* head; // pointer to first node in this SList
	// private facilitators
	void copy(const SList& other); // copies other SList into this SList
	void releaseOwnership(); // releases resources owned by this SList

public:
	SList(); // default ctor
	//special member functions
	~SList(); // dtor
	SList(SList&& other) noexcept; // move ctor
	SList(const SList& other); // copy ctor
	SList& operator=(SList&& other) noexcept; // move assignment
	SList& operator=(const SList& other); // copy assignmnet

	// an examples of an inline member function
	int size() const { return theSize; }
	// this is another example of an inlined member function (see definition)
	bool isEmpty() const;

	void clear(); // deletes all the node in this SList
	void push_front(const DataType& dataValue); // adds new node at front
	void pop_front(); // deletes the front node
	void print(std::ostream& sout) const; // prints the list elements to sout

	// Compares two SList objects for equlity. As a friend of SList, any parameter and
	// local varriable of type SList in areEqual has access to all members of SList
	friend bool areEqual(const SList& list1, const SList& list2);

	class ListUnderflow {}; // a simple local exception class
};

// insertion operator overload
std::ostream& operator<<(std::ostream& sout, const SList& source);

#endif