#include "SList.h"

/*
* Default constructor.
* Constructs an empty SList.
*/
SList::SList() : head{ nullptr }, theSize{ 0 } 
{
	// nothing to do
}

/*
* Removes (deletes) all nodes in this SList.
*/
SList::~SList()
{
	clear();
}

/*
* Releases the dynamic resources owned by this SList, leaving it
* in a stable state so that it can be destructed properly.
*/
void SList::releaseOwnership()
{
	head = nullptr; // disconnect the head pointer from its target
	theSize = 0; // indicate no nodes
}

/*
* Copy constructor.
* Constructs an SList, copying a specified SList object into it.
* @param other The specified SList object.
*/
SList::SList(const SList& other)
{
	copy(other); // copy other SList into this SList
}


/*
* Move constructor
* Constructs an SList, moving the resources of a specified SList object into it,
* leaving the specified SList object in a stable state so that it can be properly
* destructed.
* @param other The specified SList object.
*/
SList::SList(SList&& other) noexcept
{
	head = other.head; // move head pointer (hence the entire other SList)
	theSize = other.theSize; // move size
	other.releaseOwnership(); // release resources owned by other SList
}
/*
* Copy asignment.
* Assigns a specified SList object to the invoking SList object.
* @param other The specified SList object.
* @return The invoking SList object.
*/
SList& SList::operator=(const SList& other) // copy assignmnet
{
	if (this != &other) // do nothing on self-assignment
	{
		clear(); // remove all nodes from this SList
		copy(other); // copy other SList into this SList
	}
	return *this; // return the invoking object
}

/*
* Move assignment.
* Moves the entire dynamic resources of a specified SList object
* into the invoking SList object, leaving the specified SList object
* in a stable state so that it can be properly destructed.
* @param other The specified SList object.
* @return The invoking SList object.
*/
SList& SList::operator=(SList&& other) noexcept // move assignment
{
	if (this != &other) // do nothing on self-assignment
	{
		clear(); // remove all nodes from this SList
		head = other.head; // remove all nodes from this SList
		theSize = other.theSize; // including its size
		other.releaseOwnership(); // release resources owned by other SList
	}
	return *this;
}
/*
* Determines whether this SList is empty.
* @return True, if this SList is empty; otherwise, false.
*/
inline bool SList::isEmpty() const { return head == nullptr; }

/*
* Releases all the node in this SList.
*/
void SList::clear()
{
	while(!isEmpty())
	{
		pop_front();
	}

	/*
	
	if we must do it from scratch

	while (head != nullptr) //while list not empty pop the front (head) node
	{
		Node* oldhead = head; // isolate the soon to become the old head node
		head = head->next; // let head point to next node; oldhead node now isolated
		delete oldhead; // delete the isolated oldhead
	}

	*/

}

/*
* Inserts a new node with the specified data value at the front of the list.
* @param dataValue The specified data value.
*/
void SList::push_front(const DataType& dataValue)
{
	// create a Node and insert it at the head of this list at once.
	head = new Node(dataValue, head);
	++theSize; // count the newly added node
}

/*
* Removes the head node of this SList.
* @throws ListUnderflow() Thrown if this SList is empty.
*/
void SList::pop_front()
{
	if (isEmpty()) throw ListUnderflow();

	Node* temp = head; // isolate the node to pop (delete)
	head = head->next; // advance the head pointer
	delete temp; // delete the isolated node
	--theSize; // uncount the node just deleted
}

/*
* Prints the data values stored in this SList to a specified output stream.
* @param out The specified output stream.
*/
void SList::print(std::ostream& out) const
{
	out << "[ ";
	for (Node* temp = head; temp != nullptr; temp = temp->next)
	{
		out << temp->data << " ";
	}
	out << "]";
}

/*
* Copies a specified SList object into this SList.
* @param other The specified SList object.
*/
void SList::copy(const SList& other)
{
	theSize = 0; // no nodes, yet
	head = nullptr; // this is an empty list, for now
	if (other.isEmpty()) return; // nothing to do

	// so, other SList has at least one node
	Node* current = other.head; // first node to copy into this list
	head = new Node(current->data, nullptr); // first node copied
	theSize = 1; // first node counted

	// set out to copy the remaining nodes, if any
	Node* lastNode = head; // last node copied into this list,
	current = current->next; // next node to copy into this list
	while (current) // while other SList has nodes to copy into this SList
	{
		Node* newNode = new Node(current->data, nullptr);
		lastNode->next = newNode; // append the new node

		lastNode = newNode; // update lastNode
		current = current->next; // advance to next node in other SList

		++theSize; // count the newly added node
	}
}

/*
* Compares two specified SList objects for equality.
* @param list1 The first specified SList object.
* @param list2 The second specified SList object.
* return true, if the two specified SList objects are equal; otherwise, false.
*/
bool areEqual(const SList& list1, const SList& list2)
{
	// areEqual is a friend of SList, so it has access to SList's theSize
	if (list1.theSize != list2.theSize) return false; // different sizes

	// areEqual is a friend of SList, so it has access to SList::Node
	SList::Node* thisCurrent = list1.head; // advance to next node
	SList::Node* otherCurrent = list2.head; // advance to next node

	// could it be that one list is longer than the other?
	// defensive programming: this must not happen (why?)
	while (thisCurrent&& otherCurrent)
	{
		if (thisCurrent->data != otherCurrent->data) return false;
		thisCurrent = thisCurrent->next;
		otherCurrent = otherCurrent->next;
	}

	if (thisCurrent || otherCurrent) return false; // unpack this statement

	// they are equal
	return true;
}

/*
* Writes a string representaion of a specified SList object to an output stream.
* @param sout The output stream.
* @param source The specified SList object.
* @return The output stream.
*/
std::ostream& operator<<(std::ostream& sout, const SList& source)
{
	source.print(sout);
	return sout;
}