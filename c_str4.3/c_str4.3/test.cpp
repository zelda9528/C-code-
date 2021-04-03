#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;


void test()
{
	string s = "abcdefg";

	printf("%s ", s.c_str());
}


int main()
{
	test();
	return 0;
}