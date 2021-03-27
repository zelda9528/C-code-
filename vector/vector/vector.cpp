#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


template<class T>
void Print(const vector<T>&vec)
{
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//void test()
//{
//	class A {
//
//	};
//
//	vector<int>v1; 
//	vector<char>v2;
//	vector<A>v3;
//	vector<A> v4 (10);
//	A a;
//	vector<A> v5(20, a);
//
//	vector<int>v7(10);
//	vector<char>v8(10);
//	vector<int *>v9(10);
//
//	char arr[] = "123456";
//	vector<char>v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//
//	Print(v7);
//	Print(v8);
//	Print(v9);
//	Print(v10);
//}

void test()
{
	vector<int>v(3, 2);
	Print(v);
	//¸³Öµ
	v.assign(5,1);
	Print(v);

	vector<int>v2(6, 2);
	v.assign(v2.begin(),v2.end());
	Print(v);

	int arr[] = { 1,2,3,4,5,6,7 };
	v.assign(arr,arr+sizeof(arr)/sizeof(arr[0]));
	Print(v);

}

int main()
{

	test();
	return 0;
}