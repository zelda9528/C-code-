#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	string str2 = "123";
	
	//string& append(const string& str);
	str.append(str2);//123
	str.append(str2);//123123
	cout << str << endl;

	//string& append(const string& str, size_t subpos, size_t sublen);
	str.append(str2,0,2);//12312312
	cout << str << endl;


	//string& append(const char* s);
	str.append("abc");//12312312abc
	cout << str << endl;


	//string& append(const char* s, size_t n);
	str.append("zxcvbnm",4);//12312312abczxcv
	cout << str << endl;

    //string& append(size_t n, char c);
	str.append(3,'x');//12312312abczxcvxxx
	cout << str << endl;

	/*template \<class InputIterator>
		string& append (InputIterator first, InputIterator last);*/
	str.append(str2.begin(),str2.end());//12312312abczxcvxxx123
	cout << str << endl;

	char s[] = "369";
	str.append(s, s + sizeof(s) / sizeof(s[0]));//12312312abczxcvxxx123369
	cout << str << endl;

	return 0;
}