#include<iostream>
#include <algorithm> 
#include<vector>
#include<string>
using namespace std;


//删除公共字符
int main()
{
	int aim[256] = { 0 };
	string ret;
	string str;
	getline(cin,str);
	string str2;
	getline(cin,str2);

	for (size_t i=0;i<str2.size();i++)
	{
		aim[str2[i]]++;
	}

	for (size_t i=0; i < str.size(); i++)
	{
		if (aim[str[i]] == 0)
			ret += str[i];
	}
	cout << ret << endl;

	return 0;
}






//组队竞赛
//int main()
//{
//	long long ret = 0;
//	int n = 0;
//	cin >> n;
//	vector<int>arr;
//	arr.resize(3 * n);
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	std::sort(arr.begin(), arr.end());
//
//	for (int i = n; i <= 3 * n - 2; i += 2)
//	{
//		ret += arr[i];
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}
