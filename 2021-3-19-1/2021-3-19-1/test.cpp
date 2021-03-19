#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void test()
{
	string str;
	string str1("abcdefgh");
	string str2(str1);
	string str3(str1,0,5);
	string str4("zxcvbnm",5);
	string str5(5,'x');
}

int main()
{
	test();
	return 0;
}
