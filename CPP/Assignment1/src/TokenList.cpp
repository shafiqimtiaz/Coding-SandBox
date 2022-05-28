#pragma warning(disable : 4996) // to use strcpy

#include <iostream>
#include <iomanip>
#include <string>
#include "TokenList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::string;

using std::fixed;
using std::right;
using std::setw;

// Copy Ctor
TokenList::TokenList(const TokenList& other)
	: head{}, tail{}, theSize{}
{
	copy(other);
}

// Move Ctor
TokenList::TokenList(TokenList&& other) noexcept
	: head{}, tail{}, theSize{}
{
	head = move(other.head); // move head pointer (hence the entire other SList)
	tail = move(other.tail);
	theSize = move(other.theSize); // move size
	other.releaseOwnership(); // release resources owned by other SList
}

/**
* Copy assignment
* Assigns a specified TokenList object to the invoking TokenList object
*
* @param other The specified TokenList object
* @return The invoking TokenList object
*/
TokenList& TokenList::operator=(const TokenList& other)
{
	if (this != &other) // do nothing on self-assignment
	{
		clear(); // remove all nodes from this SList
		copy(other); // copy other SList into this SList
	}
	return *this; // return the invoking object
}

// move assignment
TokenList& TokenList::operator=(TokenList&& other) noexcept
{
	if (this != &other) // do nothing on self-assignment
	{
		clear(); // remove all nodes from this SList
		head = move(other.head); // remove all nodes from this SList - do it by std::move()
		tail = move(other.tail);
		theSize = move(other.theSize); // including its size - do it by std::move()
		other.releaseOwnership(); // release resources owned by other SList
	}
	return *this;
}

TokenList::~TokenList()
{
	clear();
}

void TokenList::releaseOwnership()
{
	head = nullptr; // disconnect the head pointer from its target
	tail = nullptr; // disconnect the tail pointer from its target
	theSize = 0; // indicate no nodes
}

void TokenList::clear()
{
	while (!empty())
	{
		removeFront();
	}
	head = nullptr;
	tail = nullptr;
}
// 
void TokenList::copy(const TokenList& other)
{
	theSize = 0; // no nodes, yet
	head = nullptr; // this is an empty list, for now
	tail = nullptr;
	if (other.empty()) return; // nothing to do

	// so, other TokenList has at least one node
	TNode* current = other.head; // first node to copy into this list
	head = new TNode(current->theToken, nullptr); // first node copied
	theSize = 1; // first node counted

	// set out to copy the remaining nodes, if any
	TNode* lastNode = head; // last node copied into this list,
	current = current->next; // next node to copy into this list
	while (current) // while other TokenList has nodes to copy into this SList
	{
		TNode* newNode = new TNode(current->theToken, nullptr);
		lastNode->next = newNode; // append the new node

		lastNode = newNode; // update lastNode
		current = current->next; // advance to next node in other TokenList

		++theSize; // count the newly added node
	}
	tail = new TNode(current->theToken, nullptr);
}

const Token& TokenList::front() const
{
	return head->theToken;
}

const Token& TokenList::back() const
{
	return tail->theToken;
}


size_t TokenList::size() const
{
	return theSize;
}


bool TokenList::empty() const
{
	return (head == nullptr || tail == nullptr);
}

bool TokenList::search(const Token& aToken) const
{
	TNode* curr = head;

	while (curr != nullptr)
	{
		if (aToken.compare(curr->theToken) == 0)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;
}

TokenList::TNode* TokenList::lookup(const Token& aToken) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	if (aToken.compare(head->theToken) < 0)
	{
		return nullptr;
	}

	TNode* prev = head;
	TNode* curr = head->next;

	while (prev != nullptr)
	{
		if ((prev->theToken).compare(aToken) == 0)
		{
			return prev;
		}
		prev = prev->next;
	}

	prev = head; // reset prev

	while (curr != nullptr)
	{
		if ((curr->theToken).compare(aToken) > 0)
		{
			return prev;
		}
		prev = curr;
		curr = curr->next;
	}
	return tail;
}

bool TokenList::remove(TNode* nodePtr)
{
	if (nodePtr == head)
	{
		removeFront();
		return true;
	}
	else if (nodePtr == tail)
	{
		removeBack();
		return true;
	}
	else {
		TNode* curr = head;
		while (curr->next != nullptr)
		{
			if (curr->next == nodePtr)
			{
				TNode* temp = curr->next;
				curr->next = curr->next->next;
				delete temp;

				--theSize;
				return true;
			}
			curr = curr->next;
		}
	}
	return false;
}

void TokenList::addFront(const Token& aToken)
{
	TNode* newNode = new TNode(aToken);
	newNode->next = head;
	head = newNode;
	theSize++;
	if (tail == NULL) { tail = head; } return;
}

void TokenList::addBack(const Token& aToken)
{
	TNode* newNode = new TNode(aToken);
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	theSize++;
}

bool TokenList::removeFront()
{
	if (!empty())
	{
		TNode* temp = head;
		head = head->next;
		delete temp;

		--theSize;
		return true;
	}
	else return false;
}

bool TokenList::removeBack()
{
	if (!empty())
	{
		TNode* curr = head;
		TNode* prev{};

		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}
		tail = prev;
		prev->next = nullptr;
		delete curr;

		--theSize;
		return true;
	}
	else return false;
}

void TokenList::addAfter(TNode* p, const Token& aToken)
{
	if (p == nullptr)
	{
		addFront(aToken);
	}
	TNode* newNode = new TNode(aToken);
	TNode* curr = head;

	while (curr != p)
	{
		curr = curr->next;
	}

	if (curr == tail)
	{
		addBack(aToken);
	}
	else
	{
		newNode->next = curr->next;
		curr->next = newNode;
		theSize++;
	}

}

void TokenList::addSorted(const Token& aToken)
{
	ArrayList list = aToken.getNumberList();
	int line_number;
	list.get(list.size() - 1, line_number);
	addSorted(aToken.c_str(), line_number);
}

void TokenList::addSorted(const string& str, int lineNumber)
{
	Token aToken(str.c_str(), lineNumber);
	TNode* nodePtr = lookup(aToken);

	if (nodePtr == nullptr)
	{
		addFront(aToken);
		return;
	}
	if ((nodePtr->theToken).compare(aToken) == 0)
	{
		ArrayList arr = nodePtr->theToken.getNumberList();
		int len = arr.size();

		for (int i = 0; i < len; ++i)
		{
			int temp{};
			arr.get(i, temp);

			if (!arr.contains(lineNumber))
			{
				(nodePtr->theToken).addLineNumber(lineNumber);
				return;
			}
		}
	}
	else
	{
		addAfter(nodePtr, aToken);
		return;
	}

}

void TokenList::print(ostream& sout) const
{
	if (empty()) return;
	TNode* curr = head;
	while (curr != nullptr) {
		cout << right
			<< setw(20)
			<< fixed;
		curr->theToken.print(cout);
		cout << "\n";
		curr = curr->next;
	}
}

ostream& operator<<(ostream& sout, const TokenList& TList)
{
	TList.print(sout);
	return sout;
}