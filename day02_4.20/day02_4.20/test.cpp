#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;


void test()
{
	string str;
	getline(cin, str);
	//反转整句
	reverse(str.begin(), str.end());

	//反转单词
	auto begin = str.begin();
	while (begin != str.end())
	{
		auto end = begin;
		while (end != str.end() && *end != ' ')
		{
			end++;
		}
		reverse(begin, end);
		if (end != str.end())
		{
			begin = ++end;
		}
		else
		{
			begin = end;
		}
	}
	cout << str << endl;
}

//排序子序列
//void test()
//{
//	int n = 0;
//	long long num = 0;
//	vector<int>arr;
//	cin >> n;
//	arr.resize(n+1);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	arr[n] = 0;
//	int i = 0;
//	while (i<n)
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			while (i < n&&arr[i] < arr[i + 1])
//			{
//				i++;
//			}
//			num++;
//			i++;
//		}
//		else if (arr[i] == arr[i + 1])
//			i++;
//		else
//		{
//			while (i<n&&arr[i]>arr[i + 1])
//			{
//				i++;
//			}
//			num++;
//			i++;
//		}
//
//	}
//	cout << num << endl;
//
//}


int main()
{
	test();
	return 0;
}