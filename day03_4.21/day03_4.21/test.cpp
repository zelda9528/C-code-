#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
#include<vector>
using namespace std;

//数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(vector<int> numbers) {
	size_t num[1000] = { 0 };
	for (auto i : numbers)
	{
		num[i]++;
		if (num[i] > (numbers.size() / 2))
			return i;
	}
	return 0;
}

int main()
{
	vector<int>arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);

	cout << MoreThanHalfNum_Solution(arr) << " ";

	return 0;
}


//字符串中找出连续最长的数字串
//int main()
//{
//	string str;
//	getline(cin, str);
//	int maxlen = -1e5, start = 0, tempindex = 0;   //连续最长数字串的长度maxlen、连续最长数字串的起始位置start、临时连续最长数字串的起始位置tempindex
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			int templen = 0;    //临时连续最长数字串的长度templen
//			tempindex = i;
//			while (str[i] >= '0' && str[i] <= '9')
//			{
//				i++;
//				templen++;
//			}
//			if (templen > maxlen)    //更新连续最长数字串的长度和起始位置
//			{
//				maxlen = templen;
//				start = tempindex;
//			}
//		}
//	}
//	cout << str.substr(start, maxlen) << endl;
//	return 0;
//}


//#include<string>
//#include<iostream>
//#include<queue>
//字符串中找到连续最长的数字串，返回其长度
//using namespace std;
//void test()
//{
//	int num = 0;
//	string str;
//	string ret;
//	priority_queue<int> pq;
//	getline(cin, str);
//
//
//	for (auto ch : str)
//	{
//
//		if (ch >= '0' && ch <= '9')
//			num++;
//		else
//			num = 0;
//		pq.push(num );
//
//	}
//	cout << pq.top() << " ";
//}
//int main() 
//{
//	test();
//	return 0;
//}