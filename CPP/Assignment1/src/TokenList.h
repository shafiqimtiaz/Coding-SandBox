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
	TokenList() : head{ nullptr }, tail{ nullptr }, theSize{ 0 } {} // default ctor
	TokenList(const TokenList& other); // copy ctor
	TokenList(TokenList&& other) noexcept; //move ctor
	TokenList& operator=(const TokenList& other); // copy assignment
	TokenList& operator=(TokenList&& other) noexcept; // move assignment
	virtual ~TokenList(); // virtual dtor

	bool empty() const;
	size_t size() const;
	void print(ostream& sout) const;
	const Token& front() const;
	const Token& back() const;
	void addSorted(const Token& aToken);
	void addSorted(const string& str, int lineNumber);
	bool removeFront();
	bool removeBack();
	bool search(const Token& aToken) const;
	void addFront(const Token& aToken);
	void addBack(const Token& aToken);

private:

	bool remove(TNode* nodePtr); // make public to test
	TNode* lookup(const Token& aToken) const; // make public to test
	void addAfter(TNode* p, const Token& aToken); // make public to test

	void clear();
	void releaseOwnership();
	void copy(const TokenList& other);
};

ostream& operator<<(ostream& sout, const TokenList& TList);

#endif