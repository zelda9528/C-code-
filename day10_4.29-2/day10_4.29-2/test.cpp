#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;



int fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * fun(n + 1);
}
int main()
{
	cout << fun(2) << endl;
	return 0;
}

//class Printer {
//public:
//	Printer(std :: string name) { }
//};
//class Container {
//public:
//	Container() : b("b") ,a("a") {}
//	Printer a;
//	Printer b;
//};
//int main() {
//	Container C;
//	return 0;
//}


//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x&(x - 1);
//	}
//	return count;
//}
//int main()
//{
//	cout << func(9999) << endl;
//	return 0;
//}



//int main()
//{
//	int I = 1;
//	if (I <= 0)
//		printf("****\n");
//	else
//		printf("%%%%\n");
//	return 0;
//}