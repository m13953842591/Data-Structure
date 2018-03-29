#ifndef LINKQUEUE_CPP_INCLUDED
#define LINKQUEUE_CPP_INCLUDED

#include "linkQueue.h"

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType& x)
{
    if(rear == NULL)
        front = rear = new node(x, NULL);
    else{
        rear->next = new node(x, NULL);
        rear = rear->next;
    }
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *p = front;
    elemType x = p->data;
    front = front->next;
    delete p;
    if (front == NULL) rear = NULL;
    return x;

}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
	while(!isEmpty()) deQueue();
}

#endif // LINKQUEUE_CPP_INCLUDED
