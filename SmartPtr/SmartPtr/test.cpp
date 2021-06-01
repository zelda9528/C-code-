#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
#include<thread>
using namespace std;
struct Data {
	int _y = 2021;
	int _m = 6;
	int _d = 1;

	~Data()
	{
		cout << "~Data()" << endl;
	}
};

//智能指针
//通过对象的生命周期管理资源的生命周期
//智能指针的实现：1.RAII思想；2.实现'*'和'->'操作符的功能
template<class T>
class SmartPtr {
private:
	T* _ptr;
public:
	SmartPtr(T* ptr) :_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
		cout << "~SmartPtr()" << endl;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

};
void test()
{
	cout << "test1:" << endl;
	SmartPtr<int> sp(new int);

	SmartPtr<Data> sp2(new Data);
	cout << "日期：" << sp2->_y << '.' << sp2->_m << '.' << sp2->_d << endl;;

}

//模拟实现auto_ptr
template<class T>
class AutoPtr {
private:
	T* _ptr;
public:
	AutoPtr(T* ptr):_ptr(ptr)
	{}
	//拷贝：管理权转移
	AutoPtr(AutoPtr<T>& ap) :_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	//赋值：管理权转移
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;

			ap._ptr = nullptr;
		}
		return *this;
	}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

};

void test2()
{
	cout << "test2:" << endl;

	//标准库智能指针--存在管理权转移问题，会释放被拷贝的指针，禁止使用
	auto_ptr<int> ap(new int(10));
	auto_ptr<Data> ap2(new Data);
	ap2->_y = 1999;
	ap2->_m = 3;
	ap2->_d = 19;
	cout << "日期：" << ap2->_y << '.' << ap2->_m << '.' << ap2->_d << endl;
	
	//智能指针的拷贝构造:管理权转移到新的指针
	//多个指针管理同一块内存空间，但是不会造成二次释放的问题
	auto_ptr<Data> ap3 = ap2;
}
void test3()
{
	cout << "test3:" << endl;

	AutoPtr<Data> Ap1(new Data);
	AutoPtr<Data> Ap2(Ap1);		//拷贝构造：管理权转移
}

//unique_ptr的实现
template <class T>
class UniquePtr {
private:
	T* _ptr;
public:
	UniquePtr(T* ptr) :_ptr(ptr)
	{}

	//禁止拷贝和赋值
	UniquePtr(const UniquePtr<T>& up) = delete;
	UniquePtr& operator=(const UniquePtr<T>& up) = delete;
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}

};

void test4()
{
	
	//unique_ptr:防拷贝，不能赋值
	//unique_ptr将拷贝构造和赋值运算定义为delete函数
	unique_ptr<Data> up(new Data);
	//unique_ptr<Data> up1(up);
	unique_ptr<Data> up3(new Data);
	//up3 = up;

}

template<class T>
class SharedPtr {
private:
	T* _ptr;
	size_t* _countPtr;
public:
	SharedPtr(T* ptr) 
		:_ptr(ptr)
		,_countPtr(new size_t(1))
	{}
	
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		,_countPtr(sp._countPtr)
	{
		//计数器累加
		++(*_countPtr);
	}

	SharedPtr<T> operator=(const SharedPtr<T>& sp)
	{
		if (_ptr!=sp._ptr)	//判断是否为不同资源的指针，如果是同一份资源，则不需要以下操作
		{
			//原计数器自减
			//如果计数器自减后为0，表示当前对象是最后一个管理该资源的
			//负责对资源进行释放
			if (--(*_countPtr) == 0)
			{
				delete _ptr;
				delete _countPtr;
			}
			_ptr = sp._ptr;
			_countPtr=sp._countPtr;

			//新计数器的累加
			++(*_countPtr);
		}
		return *this;
	}

	~SharedPtr()
	{
		//参考引用计数
		if (--(*_countPtr) == 0)
		{
			delete _ptr;
			delete _countPtr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
};

void test5()
{
	cout << "test5:" << endl;
	shared_ptr<Data> shp(new Data);
	cout << shp.use_count() << endl;

	shared_ptr<Data> shp2(shp);
	shared_ptr<Data> shp3(new Data);
	shp3 = shp;
	shp3 = shp2;
	cout << shp.use_count() << endl;

}

void test6()
{
	cout << "test6:" << endl;
	SharedPtr<Data> sp1(new Data);
	SharedPtr<Data> sp2(new Data);

	SharedPtr<Data> sp3(sp1);

	sp2 = sp1;
}
void fun(const SharedPtr<Data>&sp, int n)
{
	for (int i = 0; i < n; i++)
		SharedPtr<Data> copy(sp);
}

void test7()
{
	cout << "test7:" << endl;
	SharedPtr<Data> Sp(new Data);
	int n = 10;
	thread t1(fun, ref(Sp), n);
	thread t2(fun, ref(Sp), n);
	t1.join();
	t2.join();
}

int main()
{
	test();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
} 