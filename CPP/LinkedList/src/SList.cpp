#include "SList.h"

SList::SList() : head{ nullptr }, theSize{ 0 } {}

SList::~SList()
{
	clear();
}

void SList::releaseOwnership()
{
	head = nullptr; 
	theSize = 0;
}

// Copy Ctor
SList::SList(const SList& other)
{
	copy(other);
}


// Move Ctor
SList::SList(SList&& other) noexcept
{
	head = other.head;
	theSize = other.theSize;
	other.releaseOwnership();
}

// Copy Ass Op
SList& SList::operator=(const SList& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

// Move Ass Op
SList& SList::operator= (SList&& other) noexcept
{
	if (this != &other)
	{
		clear();
		head = other.head;
		theSize = other.theSize;
		other.releaseOwnership();
	}
	return *this;
}

inline bool SList::isEmpty() const { return head == nullptr; }

void SList::clear()
{
	while(!isEmpty())
	{
		pop_front();
	}
}

void SList::push_front(const DataType& dataValue)
{
	head = new Node(dataValue, head);
	++theSize;
}

void SList::pop_front()
{
	if (isEmpty()) throw ListUnderflow();
	Node* temp = head;
	head = head->next;
	delete temp;
	--theSize; 
}

void SList::print(std::ostream& out) const
{
	out << "[ ";
	for (Node* temp = head; temp != nullptr; temp = temp->next)
	{
		out << temp->data << " ";
	}
	out << "]";
}

void SList::copy(const SList& other)
{
	theSize = 0;
	head = nullptr;
	if (other.isEmpty()) return;

	Node* current = other.head;
	head = new Node(current->data, nullptr);
	theSize = 1;

	Node* lastNode = head;
	current = current->next;
	while (current)
	{
		Node* newNode = new Node(current->data, nullptr);
		lastNode->next = newNode; 

		lastNode = newNode;
		current = current->next;

		++theSize;
	}
}

bool areEqual(const SList& list1, const SList& list2)
{
	if (list1.theSize != list2.theSize) return false;

	SList::Node* thisCurrent = list1.head;
	SList::Node* otherCurrent = list2.head;

	while (thisCurrent&& otherCurrent)
	{
		if (thisCurrent->data != otherCurrent->data) return false;
		thisCurrent = thisCurrent->next;
		otherCurrent = otherCurrent->next;
	}

	if (thisCurrent || otherCurrent) return false;

	return true;
}

std::ostream& operator<<(std::ostream& sout, const SList& source)
{
	source.print(sout);
	return sout;
}