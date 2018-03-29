#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
#include "Queue.h"

using namespace std;

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
