#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1;
	string str2 = "123";
	str1 += str2;//123
	str1 += "abc";//123abc
	str1 += 'x';//123abcx

	return 0;
}