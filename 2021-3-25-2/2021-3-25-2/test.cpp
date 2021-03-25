#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


int main()
{
	string str = "mm";
	string str2 = "123";
	//string& insert(size_t pos, const string& str);
	str.insert(1,str2);//m123m
	cout << str << endl;

	//string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
	str.insert(1,str2,1,2);//m23123m
	cout << str << endl;

	//string& insert(size_t pos, const char* s);
	str.insert(0,"abc");//abcm23123m
	cout << str << endl;

	//string& insert(size_t pos, const char* s, size_t n);
	str.insert(0,"000000",5);//00000zbcm23123m
	cout << str << endl;

	/*string& insert(size_t pos, size_t n, char c);
	void insert(iterator p, size_t n, char c);*/
	str.insert(str.begin(),3,'x');//xxx00000zbcm23123m
	cout << str << endl;

	//iterator insert(iterator p, char c);
	
	/*template \<class InputIterator>
		>> void insert(iterator p, InputIterator first, InputIterator last);*/
	str.insert(str.end(),str2.begin(),str2.end());//xxx00000zbcm23123m123

	cout << str << endl;


}