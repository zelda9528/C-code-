#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;




class String {
public:
	//全缺省构造函数
	String(const char* str="")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;

		strcpy(_data, str);
	}

	//现代写法的拷贝构造
	String(const String & str):_data(nullptr),_size(0),_capacity(0)
	{
		//创建临时对象
		String tmp(str._data);
		Swap(tmp);
	}

	//现代写法重载赋值运算符
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}


	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}


	void Swap(String & str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}


	size_t size()const
	{
		return _size;
	}


	//迭代器---与指针类似
	//用*解引用，即可访问内容
	//移动：++iterator，--iterator
	//实现：字符指针
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		//首元素位置
		return _data;
	}
	iterator end()
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}


	//reserve
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间
			char*tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _data);
			//释放原来空间
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}

	//尾插
	void push_back(const char&ch)
	{
		//检查空间
		if (_size == _capacity)
		{
			size_t newC=_capacity==0?15:2*_capacity;
			reserve(newC);
		}
		_data[_size++] = ch;

		//添加结束字符'\0'
		_data[_size] = '\0';
	}

	//resize
	void resize(size_t n,const char& ch='\0')
	{
		//3.n>_capacity    需要增容
		if (n > _capacity)
		{
			reserve(n);
		}

		//2._szie<n<=_capcity
		if(n>_size)
			memset(_data + _size, ch, (n - _size) * sizeof(char));

		//1.直接修改_size
		_size = n;

		_data[_size] = '\0';

	}


	//append
	void append(const char*str)
	{
		//检查容量
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//尾插
		memcpy(_data + _size, str, sizeof(char) *len); //比srcpy更高效
		//strcpy(_data + _size, str);

		//更新size
		_size += len;
		_data[_size] = '\0';
	}


	//重载+=运算符
	String& operator+=(const char& ch)
	{
		push_back(ch);
		return *this;
	}

	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	String& operator+=(const String& str)
	{
		append(str._data);
		return *this;
	}
	
	void insert(size_t pos, const char&ch)
	{
		//检查位置
		assert(pos >= 0 && pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15:2*_capacity ;
			reserve(newC);
		}

		//移动元素:[pos,_size]从后向前移动
		for (size_t i = _size; i >= pos; i--)
		{
			_data[i + 1] = _data[i];
		}
		//插入元素
		_data[pos] = ch;

		//更新
		_size++;

		_data[_size] = '\0';

	}
	//void insert(size_t pos, const char*ch)
	
	//void insert(size_t pos, const char*ch)







	//析构函数
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}


private:
	char* _data;

	//size：有效字符的个数
	size_t _size;
	//容量
	size_t _capacity;
};

String operator+(const String& str1,const String & str2)
{
	String ret;
	ret += str1;
	ret += str2;

	return  ret;
}

String operator+(const String& str1, const char* ch)
{
	String ret;
	ret += str1;
	ret += ch;
	return ret;
}
String operator+(const String& str1, const char& str)
{
	String ret;
	ret += str1;
	ret += str;
	return ret;
}



void test()
{
	String str1("111");
	String str2("222");
	String str3, str4, str5;
		str3 = str1 + 'a';
		str4 = str1 + str2;
		str5 = str1 + "aaa";

		str1.insert(1,'a');




		//String str("123456");
	    //String str2("222");
	    //str.push_back('a');
	    //str.push_back('a');
	    //str.push_back('a');
		//str += 'c';
		//str += "111";
		//str.resize(3);
		//str.resize(10,'x');
		//str.resize(20,'b');
		//str.append("zxcv");

}
//
//void test()
//{
//	String str("0123456789");
//	cout << "for循环：";
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		cout  << str[i] << " ";
//	}
//	cout << endl;
//
//	cout << "范围for：";
//  //范围for是调用string的begin和end迭代器来实现的
//	for (const auto& ch : str)
//	{	
//		cout  << ch <<" ";
//	}
//	cout << endl;
//
//	String::iterator it = str.begin();
//	cout << "迭代器：";
//
//	while (it != str.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}




//class String {
//public:
//
//
//	//全缺省的构造函数
//	String(const char*str = "")
//		: _data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//
//	//拷贝构造-现代写法
//	String(const String&str):_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(tmp._data, _data);
//	}
//
//	//赋值运算符重载
//	/*String& operator=(const String&str)
//	{
//		String tmp(str._data);
//		swap(tmp._data, _data);
//		return *this;
//	}*/
//
//	//现代写法
//	String& operator=( String str)
//	{
//		swap(str._data, _data);
//		return *this;
//
//	}
//
//	//c_str()
//	const char* c_str()const
//	{
//		return _data;
//
//	}
//
//	//析构函数
//	/*~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}*/
//
//
//
//private:
//	char* _data;
//};
//
//
//void test()
//{
//	String str1 = "123123";
//	String str2 = str1;
//	String str3 = "123";
//
//	str3 = str1;
//
//}
