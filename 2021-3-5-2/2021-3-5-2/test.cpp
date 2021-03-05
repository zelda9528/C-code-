#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {

public:
	A(int a = 1, int b = 2, int c = 3) :_a(a), _b(b), _c(c)
	{

	}
	friend void operator<<(ostream&cout, A& a);
private:
	int _a;
	int _b;
	int _c;

};
void operator<<(ostream&cout, A& a)
{
	cout << a._a << "-" << a._b << "-" << a._c << "" << endl;
}
int main()
{
	A a;
	cout << a;
}