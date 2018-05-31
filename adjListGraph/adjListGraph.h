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

    verNode *verList;
    int Vers, Edges;

    void dfs(int v, bool visited[]) const;

  public:
    struct DijkstraNode
    {
        int node, prev, len;
        TypeOfEdge distance;
        bool known;
        bool operator<(const DijkstraNode &x)
        {
            return distance < x.distance;
        }
    };
    adjListGraph(const TypeOfVer vers[], int vSize);
    bool exist(int u, int v) const;
    bool insert(int u, int v, TypeOfEdge w);
    bool remove(int u, int v);
    void remove(const TypeOfVer &n);
    void dfs() const;
    void bfs() const;
    void Kruscal() const;
    void Prim() const;
    void Dijkstra(int start, DijkstraNode *&res);
    void printPath(int start, int end, DijkstraNode *&res);
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
