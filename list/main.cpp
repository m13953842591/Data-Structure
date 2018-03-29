#include <iostream>
#include "seqList.h"
#include "linkList.h"
using namespace std;

int main(){
    seqList <int> seq(1);
    seq.insert(0, 1);
    seq.insert(0, 2);
    seq.insert(0, 3);
    cout << "visit(1) = " << seq.visit(1) << endl;
    seq.traverse();
    seq.remove (1);
    seq.traverse();

    linkList<int> link;
    link.insert(0, 1);
    link.insert(0, 2);
    link.insert(0, 3);
    cout << "visit(1) = " << link.visit(1) << endl;
    //link.reverse();
    link.traverse();
    link.remove(1);
    link.remove(4);
    link.remove(5);
    link.traverse();
	return 0;
}
