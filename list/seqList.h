#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include "list.h"
#include <iostream>
using namespace std;
class outOfBound{};
class illegalSize{};

template <class elemType>
class seqList: public list<elemType>
{
private:
	elemType * data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	seqList(int initSize = 10);
	seqList(const seqList & obj);
	~seqList();
	int length() const {return currentLength;}
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void insert(int i, const elemType &x);
	void remove(int i);
	void clear(){currentLength = 0;}
	void traverse() const;
};
#include "seqList.cpp"
#endif
