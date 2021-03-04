#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A(int a = 1) :_a()
	{
		
	}
	void print()
	{
		cout << this->_a << endl;
	}
private:
	int _a=0;		//C++11的成员初始化新方法
					//此处的缺省值只有在无其他值可用时才会使用
					//仅限于非static成员
};

int main()
{
	A x;
	x.print();
	return 0;
}