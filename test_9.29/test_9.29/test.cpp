#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class A {
public:
	A() {
		cout << "A()\n";
	}
};

int main()
{
	//A a[2];	//2
	//auto a = new A(); //1
	//A a[2];	//2
	A* a;
	return 0;
}