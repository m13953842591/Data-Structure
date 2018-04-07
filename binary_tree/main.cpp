#include "binaryTree.h"

int main()
{
    binaryTree<int> t1;
    cout << "t1.isEmpty(): " << t1.isEmpty() << endl;
    binaryTree<char> t2;
    //cout << "t2.getRoot(): " << t2.getRoot() << endl;
    cout << "t2.size(): " << t2.size() << endl;
    cout << "t2.height(): " << t2.height() << endl;

    t2.createTree('.');
    t2.preOrder();
    t2.midOrder();
    t2.postOrder();


    return 0;
}
