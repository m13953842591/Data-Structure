#include <iostream>

using namespace std;

class A
{
private:
    int d;
public:
    A(int dd):d(dd){}
    void use(const A &x)
    {
        cout << "x.d = " << x.d << endl;
    }
};
int main()
{
    A aa(1), bb(2);
    aa.use(bb);
    return 0;
}
