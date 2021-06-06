#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	auto start = str.begin();
	while (start != str.end())
	{
		auto end = start;
		while (end!=str.end()&&*end != ' ')
		{
			end++;
		}
		reverse(start, end);
		if (end != str.end())
		{
			start = end + 1;
		}
		else
			start = end;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}

////ÅÅĞò×ÓĞòÁĞ
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> vec;
//	vec.resize(n + 1);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vec[i];
//	}
//	int i = 0;
//	int num = 0;
//	while (i < n)
//	{
//		if (vec[i] < vec[i + 1])
//		{
//			while (i < n&&vec[i] < vec[i + 1])
//			{
//				i++;
//			}
//			i++;
//			num++;
//		}
//		else if (vec[i] == vec[i + 1])
//		{
//			i++;
//		}
//		else
//		{
//			while (i<n&&vec[i]>vec[i + 1])
//			{
//				i++;
//			}
//			i++;
//			num++;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}