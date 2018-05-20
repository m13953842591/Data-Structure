#include "BinarySearchTree.h"

int main()
{
    int d[5] = {1,3,4,5,6};
    BinarySearchTree<int> b;
    for(int i = 0; i < 5; i++)
    {
        b.insert(d[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        cout << "b.find(d[i]) : " << b.find(d[i]) << endl;
    }

    return 0;
}
