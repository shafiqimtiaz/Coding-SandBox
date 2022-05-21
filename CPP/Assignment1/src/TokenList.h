#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "Token.h"
using std::ostream;

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
	size_t size{ 0 };

public:
	TokenList() : head{}, tail{}, size{} {}
	TokenList(const TokenList& other); // copy ctor
	TokenList(TokenList&& other) noexcept; //move ctor
	virtual ~TokenList();

	bool empty() const;
	void print(ostream& sout) const;
	void addFront(const Token& aToken);
	void addBack(const Token& aToken);
	bool removeFront();
	void addSorted(const Token& aToken);
private:
	void clear();
	void releaseOwnership();
	void copy(const TokenList& other);

};

ostream& operator<<(ostream& sout, const TokenList& TList);

#endif