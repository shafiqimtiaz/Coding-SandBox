#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "Token.h"
using std::ostream;
using std::string;

class TokenList
{
private:
	struct TNode
	{
		Token theToken; // the token contained in this node
		TNode* next; // Pointer to the next node or nullptr

		// Constructor
		TNode(const Token& aToken, TNode* next = nullptr)
			: theToken{ aToken }, next{ next } {}

		//disabling default features using '=delete'
		TNode() = delete; // default ctor
		TNode(const TNode& other) = delete; // copy ctor
		TNode(TNode&& other) = delete; // move ctor
		TNode& operator=(const TNode& other) = delete; // copy assignment
		TNode& operator=(TNode&& other) = delete; // move assignment

		//allowing '=default' features
		virtual ~TNode() = default;
	};

	// beging class TokenList
	TNode* head; // points to the first node in the list
	TNode* tail; // points to the last node in the list
	size_t theSize;

public:

	/**
	* Default constructor
	*/
	TokenList() : head{ nullptr }, tail{ nullptr }, theSize{ 0 } {}

	/**
	* Copy Constructor
	*/
	TokenList(const TokenList& other);

	/**
	* Move Constructor
	*/
	TokenList(TokenList&& other) noexcept;

	/**
	* Copy Assignment Operator
	*/
	TokenList& operator=(const TokenList& other);

	/**
	* Move Assignment Operator
	*/
	TokenList& operator=(TokenList&& other) noexcept;

	/**
	* TokenList Destructor
	*/
	virtual ~TokenList();

	/**
	* @return bool if TokenList empty or not
	*/
	bool empty() const;

	/**
	* @return the size of the TokenList
	*/
	size_t size() const;

	/**
	* @param sout - the TokenList ostream to be printed
	*/
	void print(ostream& sout) const;

	/**
	* @return the head node of the TokenList
	*/
	const Token& front() const;

	/**
	* @return the tail node of the TokenList
	*/
	const Token& back() const;

	/**
	* @param aToken - the Token to be added in sorted order
	*/
	void addSorted(const Token& aToken);

	/**
	* @param str - the Token string ref to be added
	* @param lineNumber - the lineNumber to be added
	*/
	void addSorted(const string& str, int lineNumber);

	/**
	* @return bool if removal of a node from front successful or not
	*/
	bool removeFront();

	/**
	* @return bool if removal of a node from back successful or not
	*/
	bool removeBack();

	/**
	* @param aToken - the Token to be searched in TokenList
	* @return bool if the Token is present in TokenList or not
	*/
	bool search(const Token& aToken) const;

	/**
	* @param aToken - the Token to be added to the front of TokenList
	*/
	void addFront(const Token& aToken);

	/**
	* @param aToken - the Token to be added to the back of TokenList
	*/
	void addBack(const Token& aToken);

private:

	/**
	* @param nodePtr - the TNode pointer to be removed from TokenList
	* @return bool if removal successful or not
	*/
	bool remove(TNode* nodePtr); // make public to test

	/**
	* @param aToken - the Token to be searched in TokenList
	* @return the TNode pointer to the Token searched in the TokenList
	*/
	TNode* lookup(const Token& aToken) const; // make public to test

	/**
	* @param p - the TNode after which to be added
	* @param aToken - the Token to be added after specified TNode
	*/
	void addAfter(TNode* p, const Token& aToken); // make public to test

	/**
	* Removes all the nodes from TokenList until there is no node
	* and then making head and tail to nullptr
	*/
	void clear();

	/**
	* Release resources owned by other TokenList
	*/
	void release();

	/**
	* Performs a deep copy of the 'other' TokenList into the invoking TokenList
	*
	* @param other - The specified TokenList object
	*/
	void copy(const TokenList& other);
};

/**
* @param sout - the TokenList ostream to be printed
* @param TList - the TokenList object ref
* @return TokenList ostream object ref
*/
ostream& operator<<(ostream& sout, const TokenList& TList);

#endif