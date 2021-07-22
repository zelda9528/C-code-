// MyJob2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


using namespace std;

string& replace_all(string& str, const string& old_value, const string& new_value)
{
	while (true) {
		string::size_type pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else break;
	}
	return str;
}

int main()
{
	LoginPage Frame;
	Frame.CreatePage();
	system("pause");
    return 0;
}

