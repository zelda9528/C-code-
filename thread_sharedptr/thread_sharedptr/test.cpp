#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
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


//shared_ptr:
//1.支持赋值和拷贝
//2.通过引用计数保证资源正确释放且不会被多次释放
//3.在多线程中，通过对引用计数进行串行操作（加解锁），保证计数更新的正确性
//4.每一个资源都有自己独立的引用计数
template<class T>
class SharedPtr {
private:
	T* _ptr;
	size_t* _countPtr;
	mutex* _mtx;	//每一份资源都有一个独立的锁
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _countPtr(new size_t(1))
		,_mtx(new mutex)
	{}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _countPtr(sp._countPtr)
		, _mtx(sp._mtx)
	{
		//计数器累加
		//++(*_countPtr);
		addCount();
	}

	SharedPtr<T> operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)	//判断是否为不同资源的指针，如果是同一份资源，则不需要以下操作
		{
			//原计数器自减
			//如果计数器自减后为0，表示当前对象是最后一个管理该资源的
			//负责对资源进行释放
			//if (--(*_countPtr) == 0)
			if(subCount()==0)
			{
				delete _ptr;
				delete _countPtr;
				delete _mtx;
			}
			_ptr = sp._ptr;
			_countPtr = sp._countPtr;

			//新计数器的累加
			//++(*_countPtr);
			addCount();
		}
		return *this;
	}

	~SharedPtr()
	{
		//参考引用计数
		//if (--(*_countPtr) == 0)
		if(subCount()==0)
		{
			delete _ptr;
			delete _countPtr;
			delete _mtx;
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

	size_t getCount()
	{
		return *_countPtr;
	}

	size_t addCount()
	{
		_mtx->lock();
		++(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}
	size_t subCount()
	{
		_mtx->lock();
		--(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

};

void fun(const SharedPtr<Data>&sp, int n)
{
	for (int i = 0; i < n; i++)
		SharedPtr<Data> copy(sp);
}

void test()
{
	cout << "test:" << endl;
	SharedPtr<Data> Sp(new Data);
	SharedPtr<Data> Sp2(new Data);

	int n = 10000;
	thread t1(fun, ref(Sp), n);
	thread t2(fun, ref(Sp), n);
	thread t3(fun, ref(Sp), n);
	thread t4(fun, ref(Sp), n); 

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	

	cout << Sp.getCount() << endl;
	cout << Sp2.getCount() << endl;

}

int main()
{
	test();
	return 0;
}