#ifndef ADJMATRIXGRAPH_H_INCLUDED
#define ADJMATRIXGRAPH_H_INCLUDED
#include <iostream>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class AdjMatrixGraph
{
  private:
    int Vers, Edges;
    TypeOfEdge **edge;
    TypeOfVer *ver;
    TypeOfEdge noEdge;

  public:
    AdjMatrixGraph(int vSize, TypeOfVer v[], TypeOfEdge noEdgeFlag);
    //insert an edge
    bool insert(int u, int v, TypeOfEdge w);
    //remove an edge
    bool remove(int u, int v);
    //see if E(u, v) exist
    bool exist(int u, int v);
    void traverse();
    ~AdjMatrixGraph();
};

#include "AdjMatrixGraph.cpp"
#endif // ADJMATRIXGRAPH_H_INCLUDED
