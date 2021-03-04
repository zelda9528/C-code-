#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class A {
public:
	A(int a):a1(a),a2(a1)
	{
		cout << a1 << " " << a2 << endl;
	}

private:
	int a2;
	int a1;

};

int main()
{
	A a(1);
	return 0;
}