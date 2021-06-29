#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void test()
{
	class A {
	public:int _a = 1;

	};

	vector<int>v1;
	vector<char>v2;
	vector<A>v3;
	vector<A> v4(10);
	A a;
	vector<A> v5(20, a);
	vector<int> v6(5, 10);


	vector<int>v7(10);
	vector<char>v8(10);
	vector<int *>v9(10);

	char arr[] = "123456";
	vector<char>v10(arr, arr + sizeof(arr) / sizeof(arr[0]));

}

int main()
{
	test();
	return 0;
}
