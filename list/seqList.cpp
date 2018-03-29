#ifndef SEQLIST_CPP_INCLUDED
#define SEQLIST_CPP_INCLUDED
#include <iostream>
#include "seqList.h"
using namespace std;

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
	if(initSize < 0) throw outOfBound();
	data = new elemType[initSize];
	currentLength = 0;
	maxSize = initSize;
}

template <class elemType>
seqList<elemType>::seqList(const seqList & obj)
{
	data = new elemType[obj.length()];
	for(int i = 0; i < obj.length(); i++) data[i] = obj[i];
	maxSize = currentLength = obj.length();
}
template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    if (i < 0 || i >= currentLength)
        throw outOfBound();
    return data[i];
}

template <class elemType>
seqList<elemType>::~seqList() {delete [] data;}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
	for(int i = 0; i < currentLength; i++)
	{
		if(x == data[i]) return i;
	}
	return -1;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
	if (i < 0 || i > currentLength) return;
	currentLength++;
	if(currentLength > maxSize) doubleSpace();
	for(int j = currentLength - 1; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i] = x;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
	if (i < 0 || i >= currentLength) return;
	for(int j = i; j < currentLength - 1; j++)
	{
		data[j] = data[j + 1];
	}
	currentLength--;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType * tmp = new elemType[2 * maxSize];
	for(int i = 0; i < currentLength; i++)
	{
		tmp[i] = data[i];
	}
	delete [] data;
	data = tmp;
	maxSize *= 2;
}

template <class elemType>
void seqList<elemType>::traverse() const
{
	for(int i = 0; i < currentLength; i++)
	{
		cout << data[i] << ' ';
	}
	cout << endl;
}

#endif // SEQLIST_H_INCLUDED
