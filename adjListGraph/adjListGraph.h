#ifndef ADJLISTGRAPH_H_INCLUDED
#define ADJLISTGRAPH_H_INCLUDED
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>

class adjListGraph
{
private:
    
    struct edgeNode
    {
        TypeOfEdge weight;
        int end;
        edgeNode * next;
        edgeNode(int e, TypeOfEdge w, edgeNode * n = NULL):
            end(e), weight(w), next(n){}
    };
    
    struct verNode
    {
        TypeOfVer value;
        TypeOfEdge* head;
        verNode(TypeOfVer v, TypeOfEdge *h = NULL):
            value(v), head(h){}
    };
    
    verNode * verList;
    int Vers, Edges;

public:
    adjListGraph(const TypeOfVer vers[], int vSize);
    bool exist(int u, int v) const;
    bool insert(int u, int v, TypeOfEdge w);
    void remove(const TypeOfNode &n);
    void dfs();
    void bfs();
    ~adjListGraph();
};

#include "adjListGraph.cpp"
#endif // ADJLISTGRAPH_H_INCLUDED
