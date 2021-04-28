#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


int test(int a)
{
	a ^= (1 << 5) - 1;
	return a;
}
int main()
{
	cout << test(21) << " ";
	return 0;
}

//void func(char **m)
//{
//	++m;
//	cout << *m << endl;
//}
//
//int main()
//{
//	static char *a[] = { "morning","afternoon","evening" };
//	char **p;
//	p = a;
//	func(p);
//	return 0;
//}