#ifndef DISJOINTSET_H_INCLUDED
#define DISJOINTSET_H_INCLUDED
#include <iostream>
#include <stack>

using namespace std;

class DisjointSet
{
  private:
    int size;
    int *parent;

  public:
    DisjointSet(int s = 100);
    ~DisjointSet();
    void Union(int root1, int root2);
    int Find(int i);
    int FindNonRecur(int i);
};

DisjointSet::DisjointSet(int s = 100)
{
    parent = new int[s];
    for(int i = 0; i < s; i++)
        parent[i] = -1;
    size = s;
}

DisjointSet::~DisjointSet()
{
    delete parent;
}

void DisjointSet::Union(int root1, int root2) //����ģ��
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

int DisjointSet::FindNonRecur(int i)
{
    if(i < 0 || i >= size) return -1;
    stack<int> s;
    int x, root;
    s.push(i);
    while(!s.empty())
    {
        x = s.top();
        if(parent[x] < 0)
        {
            root = x;
            s.pop();
            break;
        }
        s.push(parent[x]);
    }
    while(!s.empty())
    {
        x = s.top();
        parent[x] = root;
        s.pop();
    }
    return root;
}
#endif // DISJOINTSET_H_INCLUDED
