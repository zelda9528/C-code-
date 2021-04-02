#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>  //查找算法
#include<string>
#include<assert.h>
using namespace std;


struct A
{
public:
	friend ostream& operator<<(ostream& out, const A&a);

	A(int a = 1) :_a(a)
	{
		cout << "A(int)" << endl;
	}
private:
	int _a;
};

ostream& operator<<(ostream& out, const A&a)
{
	out << a._a;
	return out;
}
template <class T>
class Vector {
public:
	//迭代器类型：T*
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector():_start(nullptr),_finish(nullptr),_endOfStorage(nullptr)
	{}

	Vector(size_t n,const T&val = T()):_start(new T[n]),_finish(_start+n),_endOfStorage(_start+n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
	}
	
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last):_start(nullptr),_finish(nullptr),_endOfStorage(nullptr)
	{
		while (first != last)
		{
			pushBack(*first);
			first++;
			 
		}
	}

	void pushBack(const T& val)
	{
		//检查容量
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newCapacity);
		}
		//插入
		*_finish = val;
		//更新
		++_finish;
	}

	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//保存有效元素个数
			size_t sz = size();
			//申请空间
			T* tmp = new T[n];
			//拷贝内容
			if (_start)
			{
				//拷贝有效元素
				memcpy(tmp, _start, sizeof(T)*size());
				//释放原有空间
				delete[]_start;
			}
			//更新
			_start = tmp;

			//错误写法
			//_finish = _start + size();

			_finish = _start + sz;
			_endOfStorage = _start + n;

		}
	}
	
	size_t size()const
	{
		return _finish - _start;
	}

	size_t capacity()const
	{
		return _endOfStorage - _start;
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](const size_t pos)const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T&val)
	{
		//n > capacity
		if (n > capacity())
		{
			//增容
			reserve(n);	
		}

		//size < n <= capacity
		if (n > size())
		{
			//[size,n) 填充指定数据
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size
		_finish = _start + n;
	}


	void insert(iterator pos, const T&val)
	{
		//检查位置
		assert(pos >= _start && pos <= _finish);
		//检查容量
			
		if (_finish == _endOfStorage)
		{
			//增容会导致迭代器失效
			//保存pos和_start的偏移量
			size_t offset = pos - _start;

			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);

			//更新pos
			pos = _start + offset;
		}
		//元素移动：从后向前
		iterator end = _finish;
		while (end != pos)
		{
			*end = *(end - 1);
			end--;
		}
		
		//插入
		*pos = val;
		//更新
		_finish++;
		

	}

	iterator erase(iterator pos)
	{
		//检查位置
		assert(pos>=_start&&pos<_finish);
		//元素移动:从前向后移动
		iterator start = pos;
		while (start != _finish)
		{
			*start = *(start+1);
			start++;
		}
		//更新
		_finish--;

		return pos;
	}

	void popBack()
	{
		if (size() >= 0)
		{
			erase(end() - 1);
		}

	}

private:
	//start:第一个元素的首地址
	iterator _start;
	//finish:最后一个有效元素的下一个位置
	iterator _finish;
	//endofStOrage:空间的结尾
	iterator _endOfStorage;

};

template <class T>
void printfVector(Vector<T>&vec,const T&val)	//可读可写
{
	Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		*it = val;
		it++;
	}
	cout << endl;
}

template <class T>
void printfVector(const Vector<T>&vec)		//只读，不能进行写入
{
	Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

template<class T>
void printfVectorFor(Vector<T>&vec,const T&val)	    //可读可写
{
	for ( auto &e : vec)
	{
		cout << e << " ";
		e = val;
	}
	cout << endl;
}

template<class T>
void printfVectorFor(const Vector<T>&vec)			//只读
{
	for (const auto &e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}

template<class T>
void printfOperator(Vector<T>&vec, const T&val)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]<<" ";
		vec[i] = val;
	}
	cout << endl;

}

template<class T>
void printfOperator(const Vector<T>&vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

}

void test()
{
	Vector<int>v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	v.pushBack(6);
	v.pushBack(7);
	v.pushBack(8);

	Vector<int>::iterator it = find(v.begin(), v.end(), 6);
	if (it != v.end())
	{
		cout << *it << endl;
	}

}


//void test()
//{
//	Vector<int>v;
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	v.pushBack(1);
//	printfVector(v);
//
//	v.insert(v.begin()+1, 0);
//	printfVector(v);
//
//	v.erase(v.begin() + 1);
//	printfVector(v);
//
//	v.popBack();
//	printfVector(v);
//
//
//}

//void test()
//{
//	Vector<int>v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5);
//	v.pushBack(6);
//	cout << v.size() << endl;
//	printfVector(v);
//	v.resize(10, 0);
//	cout << v.size() << endl;
//	printfVector(v);
//
//	v.resize(50, 9);
//	cout << v.size() << endl;
//	printfVector(v);
//
//
//
//	
//}


//void test()
//{
//	Vector<A>v;
//	v.pushBack(A(1));
//	v.pushBack(A(2));
//	v.pushBack(A(3));
//	v.pushBack(A(4));
//	v.pushBack(A(5));
//	v.pushBack(A(6));
//
//	printfVector(v,A(100));
//	printfVector(v);
//
//	printfVectorFor(v, A(200));
//	printfVectorFor(v);
//	printfOperator(v, A(300));
//	printfOperator(v);
//
//}



//void test()
//{
//
//	string str = "1234567890";
//	Vector<char>v(str.begin(), str.end());
//	printfVector(v,'a');
//	printfVector(v);
//
//}


//void test()
//{
//	Vector<int> v1(5);
//	Vector<char>v2(5);
//	Vector<int*>v3(5);
//	Vector<A> v4(10,1);
//
//	
//	cout << v1.size() << endl;
//	cout << v2.size() << endl;
//	cout << v3.size() << endl;
//	cout << v4.size() << endl;
//
//	cout << v1.capacity() << endl;
//	cout << v2.capacity() << endl;
//	cout << v3.capacity() << endl;
//	cout << v4.capacity() << endl;
//
//
//
//}

int main()
{
	test();
	return 0;
}

