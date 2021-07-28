#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
using namespace std;


string func(string& s)
{
	string news;
	for (const char ch : s)
	{
		if (ch != ' ')
		{
			news += ch;
		}
		else
		{
			news += "%20";
		}
	}
	return news;
}

int main()
{
	string s = "We Are Happy";
	string result = func(s);
	cout << result << endl;

	return 0;
}