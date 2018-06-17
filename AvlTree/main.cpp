#include <iostream>
#include "AvlTree.h"
using namespace std;

int main()
{
    AvlTree<int> tree;
    int x[10]  = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++) tree.insert(x[i]);
    tree.traverse();
    for(int i = 0; i < 10; i++) {
        cout << "delete " << x[i] << endl;
        tree.remove(x[i]);
        tree.traverse();
        cout << endl;
    }
    return 0;
}
