#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void fun()
{
	try
	{
		//char* ptr = new char[0x7fffffff];
		vector<int> vec(1);
		vec.at(2)=10;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "unknow exception" << endl;
	}
}

void test()
{
	fun();
}

int main()
{
	test();
	return 0;
}