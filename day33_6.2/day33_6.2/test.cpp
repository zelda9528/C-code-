#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	 int from, to;
	 while (cin >> from >> to)
	 {
		 long sum = 0, a = 1, b = 1;	
		 for (int i = 0; i < to; ++i)
		 {
			 if (i >= from - 1)
				 sum += a;
			 swap(a, b);
			 b += a;
		 }
			 cout << sum << endl;
	 }
	 return 0;
}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main()
//{
//	int f, t;
//	while (cin >> f >> t)
//	{
//		long long count = 0;
//		vector<long long> v(80,0);
//
//		v[0] = 0;
//		v[1] = 1;
//		for (int i = 2; i < 80; i++)
//		{
//			v[i] = v[i - 1] + v[i - 2];
//		}
//		for (int i = f; i <= t; i++)
//		{
//			count += v[i];
//		}
//		cout << count << endl;
//
//	}
//	return 0;
//}


//int fib(int n)
//{
//	if (n == 0 || n == 1) 
//	{
//		return n;
//	}
//	int fn1=1, fn2=0;
//	int fn = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		fn = fn1 + fn2;
//		fn2 = fn1;
//		fn1 = fn;
//	}
//	return fn;
//}
//
//int main()
//{
//	int f = 0;
//	int t = 0;
//	while (cin >> f >> t)
//	{
//		int sum = 0;
//		for (int i = f; i <= t; i++)
//		{
//			sum += fib(i);
//		}
//		cout << sum << endl;
//	}
//
//	
//	return 0;
//}

