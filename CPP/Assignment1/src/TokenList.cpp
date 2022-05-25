#pragma warning(disable : 4996) // to use strcpy

#include <iostream>
#include <cctype>
#include <cstring>
#include "TokenList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

TokenList::TokenList(const TokenList& other)
{
	copy(other);
}

TokenList::TokenList(TokenList&& other) noexcept
{
	head = other.head; // move head pointer (hence the entire other SList)
	tail = other.tail;
	theSize = other.theSize; // move size
	other.releaseOwnership(); // release resources owned by other SList
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
	while(!empty())
	{
		removeFront();
	}
}

void TokenList::copy(const TokenList& other)
{
	theSize = 0; // no nodes, yet
	head = nullptr; // this is an empty list, for now
	if (other.empty()) return; // nothing to do

	// so, other SList has at least one node
	TNode* current = other.head; // first node to copy into this list
	head = new TNode(current->theToken, nullptr); // first node copied
	theSize = 1; // first node counted

	// set out to copy the remaining nodes, if any
	TNode* lastNode = head; // last node copied into this list,
	current = current->next; // next node to copy into this list
	while (current) // while other SList has nodes to copy into this SList
	{
		TNode* newNode = new TNode(current->theToken, nullptr);
		lastNode->next = newNode; // append the new node

		lastNode = newNode; // update lastNode
		current = current->next; // advance to next node in other SList

		++theSize; // count the newly added node
	}
}


bool TokenList::search(const Token& aToken) const
{
	TNode* current = head;
	while (current)
	{
		if (current->theToken.compare(aToken) == 0)
		{
			return true;
		}
		current = current->next;
	}
	return false;
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
		TNode* temp = head; // isolate the node to pop (delete)
		head = head->next; // advance the head pointer
		delete temp; // delete the isolated node
		--theSize; // uncount the node just deleted

		return true;
	}
	else return false;
}

void TokenList::addSorted(const Token& aToken)
{
	if (head == NULL)
	{
		addFront(aToken);
	}
	else if (tail == NULL)
	{
		addBack(aToken);
	}
	else if (aToken.compare(head->theToken) < 0)
	{
		addFront(aToken);
	}
	else if (aToken.compare(head->theToken) > 0)
	{
		addBack(aToken);
	}
	else if (aToken.compare(tail->theToken) < 0)
	{
		addBack(aToken);
	}
	else if (aToken.compare(tail->theToken) > 0)
	{
		addFront(aToken);
	}
	else if (aToken.compare(head->theToken) == 0 || aToken.compare(tail->theToken) == 0)
	{
		int len = aToken.getNumberList().size();

		for (size_t i = 0; i < len; ++i)
		{
			int a{};
			aToken.getNumberList().get(i, a);
			head->theToken.addLineNumber(a);
		}
	}
}


void TokenList::print(ostream& sout) const
{
	if (head != nullptr)
	{
		sout << "[" << endl;
		for (TNode* temp = head; temp != nullptr; temp = temp->next)
		{
			sout << temp->theToken << endl;
		}
		sout << "]";
	}
	else
	{
		sout << "[ ]";
	}
}

ostream& operator<<(ostream& sout, const TokenList& TList)
{
	TList.print(sout);
	return sout;
}