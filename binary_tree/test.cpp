#include <cstdio>
#include <iostream>

using namespace std;

class test
{
private:
	int data;
public:
	test();
	test(int d):data(d){}
	void processData(const test &t){
		cout << t.data;
	}

};

int main()
{
	test t(1), s(2);
	s.processData(t);
	return 0;
}//?