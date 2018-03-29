#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include "list.h"
class OutOfBound{};
class IllegalSize{};

template<class elemType>
class linkList: public list<elemType>
{
private:
	struct node
	{
		elemType data;
		node * next;
		node():next(NULL){}
		node(const elemType &x, node * n):data(x), next(n){}
		~node(){}
	};
	node *head;

public:
	linkList(){head = new node();}
	linkList(const linkList<elemType> &l1);
	~linkList() {clear(); delete head;}
	int length() const;
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void insert(int i, const elemType &x);
	void remove(int i);
	void clear();
	void traverse() const;
};

#include "linkList.cpp"
#endif // LINKLIST_H_INCLUDED
