#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	map<char, int> map;
	for (const char& e : str2)
	{
		map[e]++;
	}

	for (const char& e : str1)
	{
		if (map[e] == 0)
			cout << e;
	}
	cout << endl;

	return 0;
}