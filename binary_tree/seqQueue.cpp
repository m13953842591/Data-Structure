#ifndef SEQQUEUE_CPP_INCLUDED
#define SEQQUEUE_CPP_INCLUDED

#include "seqQueue.h"

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
	elemType * tmp = new elemType[2 * maxSize];
	int i = 0;
	while((i + front) % maxSize != rear){
		tmp[i] = elem[(i + front + 1) % maxSize];
		i++;
	}
	front = -1;
	rear = i - 1;
	maxSize *= 2;
	delete [] elem;
	elem = tmp;
}

template <class elemType>
seqQueue<elemType>::seqQueue(int m)
{
	elem = new elemType[m];
	maxSize = m;
	front = rear = -1;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType& x)
{
	if((rear + 1) % maxSize == front) doubleSpace();
	rear = (rear + 1) % maxSize;
	elem[rear] = x;
}

template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
	front = (front + 1) % maxSize;
	return elem[front];
}

template <class elemType>
seqQueue<elemType>::~seqQueue()
{
	delete[] elem;
}

#endif // SEQQUEUE_CPP_INCLUDED
