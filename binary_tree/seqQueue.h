#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
#include <iostream>
#include <cstdio>
using namespace std;

template <class elemType>
class Queue
{
public:
	virtual bool isEmpty() const = 0;
	virtual void enQueue(const elemType& x) = 0;
	virtual elemType deQueue() = 0;
	virtual elemType getHead() const = 0;
	virtual ~Queue(){};
};

template <class elemType>
class seqQueue : public Queue<elemType>
{
private:
	elemType * elem;
	int maxSize;
	int front, rear;

	void doubleSpace();
public:
	seqQueue(int m = 10);
	bool isEmpty() const {return rear == front;}
	void enQueue(const elemType& x);
	elemType deQueue();
	elemType getHead() const{return elem[(front + 1) % maxSize];}
	~seqQueue();
};

#include "seqQueue.cpp"
#endif // SEQQUEUE_H_INCLUDED
