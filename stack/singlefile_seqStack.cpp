#include <iostream>
#include <fstream>
using namespace std;

class outOfBound {};
class illegalSize {};

template <class elemType>
class seqStack
{
private:
	elemType * elem;
	
	int maxSize;
	int head;
	void doubleSpace()
	{
		elemType * tmp = new elemType[2 * maxSize];
		for(int i = 0; i < maxSize; i++)
			tmp[i] = elem[i];
		delete elem;
		elem = tmp;
		maxSize *= 2;
	}

public:
	seqStack(int initSize = 10)
	{
		if(initSize < 0) throw illegalSize();
		elem = new elemType[initSize];
		maxSize = initSize;
		head = -1;
	}
	bool isEmpty() const {return head == -1; }
	elemType top() const
	{
		if(isEmpty()) throw outOfBound();
		return elem[head];
	}

	elemType pop()
	{
		if(isEmpty()) throw outOfBound();
		return elem[head--];
	}	
	void push(const elemType &x)
	{
		if(head == maxSize - 1) doubleSpace();
		elem[++head] = x;
	}

	~seqStack(){delete elem;}
};


int main()
{
    printf("seqStack\n");
    seqStack<int> st;
    for (int i = 0; i < 15; ++ i) {
        st.push(i);
    }
    while (!st.isEmpty())
        printf("%d ", st.pop());
    return 0;
}
