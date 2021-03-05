#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {

public:
	A(int a = 1, int b = 2, int c = 3) :_a(a), _b(b), _c(c)
	{

	}
	friend ostream& operator<<(ostream&cout, A& a);//返回值为输出流对象的引用
private:
	int _a;
	int _b;
	int _c;

};
ostream& operator<<(ostream&cout, A& a)
{
	cout << a._a << "-" << a._b << "-" << a._c << "" << endl;
	return cout;
}
int main()
{
	A a,b;
	cout << a << b;
}