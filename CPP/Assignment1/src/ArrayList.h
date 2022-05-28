#ifndef ARRAYLIST_H
#define ARRAYLIST_H
using std::ostream;

class ArrayList
{
public:
	/**
	* Default constructor
	*/
	ArrayList() : capacity{ 1 }, used{ 0 }, pArray{ new int[1] } {}

	/**
	* Copy constructor
	*/
	ArrayList(const ArrayList& source);

	/**
	* Move constructor
	*/
	ArrayList(ArrayList&& source) noexcept;

	/**
	* Copy assignment operator
	*/
	ArrayList& operator=(const ArrayList& rhs);

	/**
	* Move assignment operator
	*/
	ArrayList& operator=(ArrayList&& rhs) noexcept;

	/**
	* ArrayList Destructor
	*/
	virtual ~ArrayList();

	/**
	* @return bool if ArrayList is empty or not
	*/
	bool empty() const;

	/**
	* @return bool if ArrayList is full or not
	*/
	bool full() const;

	/**
	* @return the the number of elements in the ArrayList
	*/
	int size() const;

	/**
	* @param x - value to be inserted to the ArrayList
	*/
	void pushBack(int x);

	/**
	* @param x - value to be checked in the ArrayList
	* @return bool if int x is present in the ArrayList
	*/
	bool contains(int x) const;

	/**
	* @param position - element position in ArrayList
	* @param &value - variable ref in which element to be placed
	* @return bool if value placed
	*/
	bool get(int position, int& value) const;

	/**
	* @return the total capacity of the ArrayList
	*/
	int getCapacity() const;

	/**
	* @param sout - the ArrayList ostream to be printed
	*/
	void print(ostream& sout) const;

private:

	/**
	* doubles the ArrayList when invoked
	*/
	void resize();

	int capacity;
	int used;
	int* pArray;
};

/**
* @param sout - the ArrayList ostream to be printed
* @param source - the ArrayList object ref
* @return ArrayList ostream object ref
*/
ostream& operator<<(ostream& sout, const ArrayList& source);

#endif