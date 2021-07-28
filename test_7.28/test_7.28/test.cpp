#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

int* bigNumberSum(const string & s1,const string &s2)
{

	int maxLength = s1.length() > s2.length() ? s1.length() : s2.length();

	int* arrA = new int(maxLength + 1);
	int* arrB = new int(maxLength + 1);

	for (int i = 0; i < s1.length(); i++)
	{
		arrA[i] = s1[s1.end()-1-i];
	}
}

int main()
{
	cout << bigNumberSum("15802907963", "15802907963") << endl;
	return 0;
}