#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

#include "Queue.h"

template <class elemType>
class linkQueue
{
private:
	struct node
	{
		elemType data;
		node * next;
		node(): next(NULL){}
		node(const elemType &x, node *tmp):data(x),next(tmp){}
		~node(){}
	};

	node *front, *rear;
public:
	linkQueue():front(NULL), rear(NULL) {}
	//Note that the pointer front, rear is not preset NULL automatically,
	//which means we should set it to NULL manually!
	bool isEmpty() const {return front == NULL;}
	void enQueue(const elemType& x);
	elemType deQueue();
	elemType getHead() const{return front->data;}
	~linkQueue();
};

#include "linkQueue.cpp"

#endif // LINKQUEUE_H_INCLUDED
