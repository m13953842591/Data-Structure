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
        int end;
        TypeOfEdge weight;
        edgeNode *next;
        edgeNode() : next(NULL) {}
        edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) : end(e), weight(w), next(n) {}
    };

    struct verNode
    {
        TypeOfVer value;
        edgeNode *head;
        verNode() : head(NULL) {}
        verNode(TypeOfVer v, edgeNode *h = NULL) : value(v), head(h) {}
    };
    struct EulerNode
    {
        int NodeNum;
        EulerNode *next;
        EulerNode(int ver)
        {
            NodeNum = ver;
            next = NULL;
        }
    }

    verNode *verList;
    int Vers, Edges;
    void dfs(int v, bool visited[]) const;
    EulerNode * EulerCircuit(int start, EulerNode * &end);
    
  public:
    TypeOfEdge *dst;
    int *len;
    int *prev;

    adjListGraph(const TypeOfVer vers[], int vSize);
    bool exist(int u, int v) const;
    bool insert(int u, int v, TypeOfEdge w);
    bool remove(int u, int v);
    void remove(const TypeOfVer &n);
    void dfs() const;
    void bfs() const;
    void Kruscal() const;
    void Prim() const;
    void Dijkstra(int start);
    void printPath(int start, int end);
    void EulerCircuit() const;
    void topSort() const;
    ~adjListGraph();
};

template <class TypeOfEdge>
struct edge
{
    int begin, end;
    TypeOfEdge weight;
    edge(int b, int e, TypeOfEdge w) : begin(b), end(e), weight(w) {}
    bool operator<(const edge &e)
    {
        return weight < e.weight;
    }
};

#include "adjListGraph.cpp"
#endif // ADJLISTGRAPH_H_INCLUDED
