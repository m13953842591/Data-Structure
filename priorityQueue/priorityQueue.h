#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <iostream>
using namespace std;

template <class Type>
class priorityQueue
{
  private:
	Type *array;
	int currentSize;
	int maxSize;

	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
	void percolateUp(int hole);

  public:
	priorityQueue(int capacity = 100)
	{
		array = new Type[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	priorityQueue(const Type *data, int size);
	~priorityQueue() { delete array; }
	bool isEmpty() const { return currentSize == 0; }
	void enQueue(const Type &x);
	Type deQueue();
	Type getHead() { return array[1]; }
};

#include "priorityQueue.cpp"

#endif // PRIORITYQUEUE_H_INCLUDED
