#include <iostream>
#include <cstdio>
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

class DisjointSet
{
  private:
    int size;
    int *parent;

  public:
    DisjointSet(int s);
    ~DisjointSet();
    void Union(int root1, int root2);
    int Find(int i);
    int FindNonRecur(int i);
};

struct edge
{
    int begin, end, weight;
    bool operator<(const edge &e) const
    {
        return weight < e.weight;
    }
};

template <class Type>
void priorityQueue<Type>::doubleSpace()
{
    Type *tmp = array;
    array = new Type[2 * maxSize];
    for (int i = 0; i <= currentSize; ++i)
    {
        array[i] = tmp[i];
    }
    maxSize *= 2;
    delete[] tmp;
}

template <class Type>
void priorityQueue<Type>::percolateUp(int hole)
{
    Type tmp = array[hole];
    while (hole != 1)
    {
        if (tmp < array[hole / 2])
        {
            array[hole] = array[hole / 2];
            hole /= 2;
        }
        else
            break;
    }
    array[hole] = tmp;
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
    if (currentSize == maxSize)
        doubleSpace();
    int hole = ++currentSize;
    array[hole] = x;
    percolateUp(hole);
}

template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
    if (hole < 1 || currentSize < hole)
        return;
    Type tmp = array[hole];
    int child;
    while (hole * 2 <= currentSize)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++;

        if (array[child] < tmp)
        {
            array[hole] = array[child];
            hole = child;
        }
        else
            break;
    }
    array[hole] = tmp;
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type tmp = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; --i)
        percolateDown(i);
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type *data, int size)
{
    maxSize = size + 10;

    currentSize = size;
    array = new Type[maxSize];

    for (int i = 0; i < size; ++i)
    {
        array[i + 1] = data[i];
    }
    buildHeap();
}

DisjointSet::DisjointSet(int s)
{
    parent = new int[s];
    for (int i = 0; i < s; i++)
        parent[i] = -1;
    size = s;
}

DisjointSet::~DisjointSet()
{
    delete parent;
}

void DisjointSet::Union(int root1, int root2)
{

    if (root1 == root2)
        return;
    if (parent[root1] < parent[root2])
    {
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }

    else
    {
        parent[root2] = parent[root1] + parent[root2];
        parent[root1] = root2;
    }
}
int DisjointSet::Find(int i)
{
    if (parent[i] < 0)
        return i;
    return parent[i] = Find(parent[i]);
}

int maxSize = 10001;

int main(int argc, char const *argv[])
{
    freopen("in", "r", stdin);
    int n, m, minWeight = 0, edgeAccepted = 0, u, v;
    priorityQueue<edge> q;
    edge curEdge;
    DisjointSet s(maxSize);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> curEdge.begin >> curEdge.end >> curEdge.weight;
        q.enQueue(curEdge);
    }

    while (edgeAccepted < n - 1)
    {
        curEdge = q.deQueue();

        u = s.Find(curEdge.begin);
        v = s.Find(curEdge.end);
        if (u != v)
        {
            //cout << curEdge.begin << '\t' << curEdge.end << '\t' << curEdge.weight << endl;
            s.Union(u, v);
            minWeight += curEdge.weight;
            edgeAccepted++;
        }
    }

    cout << minWeight;
    fclose(stdin);
    return 0;
}
