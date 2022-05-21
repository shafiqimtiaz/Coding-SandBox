#ifndef SLIST_H
#define SLIST_H

#include <iostream>
using std::ostream;

using DataType = int;

class SList
{
private:
	struct Node
	{
		Node(DataType data, Node* next)
			: data{ data }, next{ next } {}
		DataType data;
		Node* next;
	};
	int theSize;
	Node* head;
	void copy(const SList& other);
	void releaseOwnership();

public:
	SList();
	~SList();
	SList(SList&& other) noexcept;
	SList(const SList& other);
	SList& operator=(SList&& other) noexcept;
	SList& operator=(const SList& other);

	int size() const { return theSize; }
	bool isEmpty() const;

	void clear();
	void push_front(const DataType& dataValue);
	void pop_front();
	void print(std::ostream& sout) const;
	friend bool areEqual(const SList& list1, const SList& list2);

	class ListUnderflow {};
};

std::ostream& operator<<(std::ostream& sout, const SList& source);

#endif