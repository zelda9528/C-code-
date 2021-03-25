#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class String {
public:


	//全缺省的构造函数
	String(const char*str = "")
		: _data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}

	//拷贝构造
	String(const String&str):_data(new char[strlen(str._data)+1])
	{
		//深拷贝
		strcpy(_data,str._data);
	}

	//赋值运算符重载
	String& operator=(String &str)
	{
		if (this != &str)
		{
			//销毁原空间
			delete[]_data;
			//申请新空间
			_data = new char[strlen(str._data) + 1];
			//拷贝内容
			strcpy(_data,str._data);
		}
		return *this;
	}


	//c_str()
	const char* c_str()const
	{ 
		return _data;
	}

	//析构函数
	~String()
	{
		if (_data)
		{
			delete [] _data;
			_data = nullptr;
		}
	}



private:
	char* _data;
};


void test()
{
	String str1 ("123123123");			//默认构造
	String str2(str1);					//拷贝构造

	String str3 ;
	str3 = str1;
}

int main()
{
	test();
	return 0;
}