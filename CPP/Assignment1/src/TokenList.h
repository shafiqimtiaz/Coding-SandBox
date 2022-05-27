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
	TNode* head{ nullptr }; // points to the first node in the list
	TNode* tail{ nullptr }; // points to the last node in the list
	size_t theSize{ 0 };

public:
	TokenList() : head{}, tail{}, theSize{} {}
	TokenList(const TokenList& other); // copy ctor
	TokenList(TokenList&& other) noexcept; //move ctor
	TokenList& operator=(const TokenList& other);
	TokenList& operator=(TokenList&& other) noexcept;
	virtual ~TokenList();
	
	bool search(const Token& aToken) const;
	const Token& front() const;
	const Token& back() const;
	size_t size() const;
	bool empty() const;
	void print(ostream& sout) const;
	void addFront(const Token& aToken);
	void addBack(const Token& aToken);
	bool removeFront();
	bool removeBack();
	void addSorted(const Token& aToken);
	void addSorted(const string& str, int lineNumber);

	bool remove(TNode* nodePtr); // make private
	TNode* lookup(const Token& aToken) const; // make private
	void addAfter(TNode* p, const Token& aToken); // make private

private:
	void clear();
	void releaseOwnership();
	void copy(const TokenList& other);
};

ostream& operator<<(ostream& sout, const TokenList& TList);

#endif