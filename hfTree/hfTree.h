#ifndef HFTREE_H_INCLUDED
#define HFTREE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

template <class Type>
class hfTree
{
private:
	struct Node
	{
		Type data;
		int weight;
		int parent, left, right;
	};

	int length;
	Node *elem;
public:
	struct hfCode
	{
		Type data;
		string code;
	};
	hfTree(const Type *x, const int *w, int size);
	void getCode(hfCode result[]);
	~hfTree(){delete []elem;}
};


#include "hfTree.cpp"
#endif // HFTREE_H_INCLUDED
