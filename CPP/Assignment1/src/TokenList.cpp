#include <iostream>
#include <string>
#include "TokenList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::string;

// extra modules needed for ostrean formatting
#include <iomanip>
using std::fixed;
using std::right;
using std::setw;

/**
* Copy Constructor
* Creates the specified TokenList object by copying the invoking TokenList object
*
* @param other - The specified TokenList object
*/
TokenList::TokenList(const TokenList& other)
	: head{}, tail{}, theSize{}
{
	copy(other);
}

/**
* Move Constructor
* Creates the specified TokenList object by moving the invoking TokenList object
*
* @param other - The specified TokenList object
*/
TokenList::TokenList(TokenList&& other) noexcept
	: head{}, tail{}, theSize{}
{
	head = move(other.head); // move head pointer (hence the entire other SList)
	tail = move(other.tail);
	theSize = move(other.theSize); // move size
	other.release(); // release resources owned by other SList
}

/**
* Copy Assignment Operator
* Copies a specified TokenList object to the invoking TokenList object
*
* @param other - The specified TokenList object
* @return The invoking TokenList object
*/
TokenList& TokenList::operator=(const TokenList& other)
{
	if (this != &other) // check for self assignment
	{
		clear(); // remove all nodes from this TokenList
		copy(other); // copy other TokenList into this TokenList
	}
	return *this; // return the invoking object
}

/**
* Move Assignment Operator
* Moves a specified TokenList object to the invoking TokenList object
*
* @param other - The specified TokenList object
* @return The invoking TokenList object
*/
TokenList& TokenList::operator=(TokenList&& other) noexcept
{
	if (this != &other) // check for self assignment
	{
		clear(); // remove all nodes from this TokenList
		head = move(other.head); // move the head
		tail = move(other.tail); // move the tail
		theSize = move(other.theSize); // move the size
		other.release(); // release resources owned by other TokenList
	}
	return *this; // return the invoking object
}

/**
* TokenList Destructor
*
* Destroys the TokenList object by removing all nodes til the end of execution scope
* by calling function clear()
*/
TokenList::~TokenList()
{
	clear();
}


/**
* Release resources owned by other TokenList
*/
void TokenList::release()
{
	head = nullptr; // disconnect the head pointer from its target
	tail = nullptr; // disconnect the tail pointer from its target
	theSize = 0; // make the size to 0
}


/**
* Removes all the nodes from TokenList until there is no node
* and then making head and tail to nullptr
*/
void TokenList::clear()
{
	while (!empty())
	{
		removeFront();
	}
	head = nullptr;
	tail = nullptr;
}

/**
* Performs a deep copy of the 'other' TokenList into the invoking TokenList
*
* @param other - The specified TokenList object
*/
void TokenList::copy(const TokenList& other)
{
	// initialing the TokenList to be copied into
	theSize = 0; // the size is 0
	head = nullptr; // head points no where
	tail = nullptr; // tail points no where
	if (other.empty()) return; // if TokenList empty, do nothing

	// copying the head node from 'other' TokenList
	TNode* current = other.head; // the head node to copies
	head = new TNode(current->theToken, nullptr); // head copied
	theSize = 1; // increment size of TokenList by 1

	// copy the remaining available nodes
	TNode* lastNode = head; // last node copied into this Tokenlist
	current = current->next; // next node to copy into this Tokenlist
	while (current) // while 'other' TokenList has nodes to copy into this SList
	{
		TNode* newNode = new TNode(current->theToken, nullptr);
		lastNode->next = newNode; // append the new node

		lastNode = newNode; // update lastNode
		current = current->next; // advance to next node in other TokenList

		++theSize; // count the newly added node
	}
	tail = new TNode(current->theToken, nullptr); // add the tail to the newly created TokenList
}

/**
* @return the head node of the TokenList
*/
const Token& TokenList::front() const
{
	return head->theToken;
}

/**
* @return the tail node of the TokenList
*/
const Token& TokenList::back() const
{
	return tail->theToken;
}


/**
* @return the size of the TokenList
*/
size_t TokenList::size() const
{
	return theSize;
}

/**
* @return bool if TokenList empty or not
*/
bool TokenList::empty() const
{
	return (head == nullptr || tail == nullptr);
}

/**
* @param aToken - the Token to be searched in TokenList
* @return bool if the Token is present in TokenList or not
*/
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

/**
* @param aToken - the Token to be searched in TokenList
* @return the TNode pointer to the Token searched in the TokenList
*/
TokenList::TNode* TokenList::lookup(const Token& aToken) const
{
	// if no node in TokenList, returns nullptr
	if (head == nullptr)
	{
		return nullptr;
	}

	// if no Token value is less than nullptr return nullptr
	if (aToken.compare(head->theToken) < 0)
	{
		return nullptr;
	}

	TNode* prev = head;
	TNode* curr = head->next;

	// checking if any Token in the TokenList matches aToken
	while (prev != nullptr)
	{
		if ((prev->theToken).compare(aToken) == 0)
		{
			return prev; // if match, return the matching TNode
		}
		prev = prev->next; // move to next node
	}

	prev = head; // reset prev

	// checking if any Token in the TokenList greater than aToken
	while (curr != nullptr)
	{
		if ((curr->theToken).compare(aToken) > 0)
		{
			return prev; // if greater, return the previous TNode
		}
		prev = curr; // make prev equal to curr
		curr = curr->next; // move to next node
	}
	// if there is no match or greater Token than aToken, return the tail node
	return tail;
}

/**
* @param nodePtr - the TNode pointer to be removed from TokenList
* @return bool if removal successful or not
*/
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

		// traverse the TokenList until curr reaches nullptr
		while (curr->next != nullptr)
		{
			// if curr->next pointer is equal to nodePtr
			if (curr->next == nodePtr)
			{
				TNode* temp = curr->next; // take the curr->next pointer to temp
				curr->next = curr->next->next; // assign the curr->next->next value to curr->next
				// by this, the curr->next will skip a node in the middle effectively disconnecting
				// the nodePtr node
				delete temp; // delete the curr->next

				--theSize; // decrement the TokenList size
				return true;
			}
			curr = curr->next; // move to next node
		}
	}
	return false;
}

/**
* @param aToken - the Token to be added to the front of TokenList
*/
void TokenList::addFront(const Token& aToken)
{
	TNode* newNode = new TNode(aToken);
	newNode->next = head;
	head = newNode;
	theSize++;
	if (tail == nullptr) { tail = head; } return;
}

/**
* @param aToken - the Token to be added to the back of TokenList
*/
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

/**
* @return bool if removal of a node from front successful or not
*/
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


/**
* @return bool if removal of a node from back successful or not
*/
bool TokenList::removeBack()
{
	if (!empty())
	{
		TNode* curr = head;
		TNode* prev{};

		// traverse the TokenList until curr reaches nullptr
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}

		// reached at end of TokenList and remove the end node
		tail = prev;
		prev->next = nullptr;
		delete curr;

		--theSize;
		return true;
	}
	else
	{
		return false;
	}
}


/**
* @param p - the TNode after which to be added
* @param aToken - the Token to be added after specified TNode
*/
void TokenList::addAfter(TNode* p, const Token& aToken)
{
	// check if p is null ptr
	if (p == nullptr)
	{
		addFront(aToken); // if yes, then add aToken to front
	}
	TNode* newNode = new TNode(aToken);
	TNode* curr = head;

	// traverse the TokenList until curr reaches the end
	while (curr != p)
	{
		curr = curr->next;
	}

	// check if curr reached tail
	if (curr == tail)
	{
		addBack(aToken); // if yes, add aToken to the back
	}
	else
	{
		// add the newNode just before the tail
		newNode->next = curr->next;
		curr->next = newNode;
		theSize++;
	}

}

/**
* @param aToken - the Token to be added in sorted order
*/
void TokenList::addSorted(const Token& aToken)
{
	ArrayList list = aToken.getNumberList(); // get number list from aToken
	int lineNumber{};
	list.get(list.size() - 1, lineNumber); // place number list and push it to lineNumber
	addSorted(aToken.c_str(), lineNumber); // add the aToken string and lineNumber
}

/**
* @param str - the Token string ref to be added
* @param lineNumber - the lineNumber to be added
*/
void TokenList::addSorted(const string& str, int lineNumber)
{
	Token aToken(str.c_str(), lineNumber);
	TNode* nodePtr = lookup(aToken); // find the node where aToken is to be inserted

	if (nodePtr == nullptr) // check if the nodePtr is equal to the nullptr
	{
		addFront(aToken); // if yes, add aToken to the front
		return;
	}
	if ((nodePtr->theToken).compare(aToken) == 0) // check if nodePtr token is equal to aToken, if match, dont add aToken, add aToken number list
	{
		ArrayList arr = nodePtr->theToken.getNumberList(); // get nodePtr number list
		int len = arr.size(); // get the length of the number list

		// traverse the number list
		for (int i = 0; i < len; ++i)
		{
			int temp{};
			arr.get(i, temp);

			// check for repeatations - if no repeat then only then add line number
			if (!arr.contains(lineNumber))
			{
				(nodePtr->theToken).addLineNumber(lineNumber);
				return;
			}
		}
	}
	else
	{
		// add the aToken to a position after the nodePtr
		addAfter(nodePtr, aToken);
		return;
	}

}

/**
* @param sout - the TokenList ostream to be printed
*/
void TokenList::print(ostream& sout) const
{
	if (empty()) return; // if TokenList empty, do nothing
	TNode* curr = head;

	// traverse the TokenList
	while (curr != nullptr) {
		cout << right << setw(20) << fixed; // for ostream formatting
		curr->theToken.print(cout); // print theToken
		cout << "\n";
		curr = curr->next; // move to next node
	}
}

/**
* @param sout - the TokenList ostream to be printed
* @param TList - the TokenList object ref
* @return TokenList ostream object ref
*/
ostream& operator<<(ostream& sout, const TokenList& TList)
{
	TList.print(sout);
	return sout;
}