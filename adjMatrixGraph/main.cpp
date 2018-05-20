#include <iostream>
#include <string>
#include "AdjMatrixGraph.h"
using namespace std;

int main()
{
    string spots[5]{"Jinan", "Beijing", "Xian", "Chengdu", "Nanjing"};
    AdjMatrixGraph<string, double> flight(5, spots, 3000000.0);
    flight.traverse();
    //now we add a flight from Jinan to Beijing which cost 1000 yuan
    flight.insert(0, 1, 1000);
    //and then we add a flight from Xian to Nanjing which cost 800 yuan
    flight.insert(2, 4, 800);
    //see the result;
    cout << "now we added two flights" << endl;
    flight.traverse();

    // we delete the flight from Xian to Nanjing
    flight.remove(2, 4);
    cout << "now we delete one flights" << endl;
    flight.traverse();
    return 0;
}
