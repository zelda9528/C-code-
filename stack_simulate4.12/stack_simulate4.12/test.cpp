#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<vector>
using namespace std;

template <class T>
class Stack {
public:
	void push(const T&val)
	{
		st_.push_back(val);
	}

	void pop()
	{
		st_.pop_back();
	}

	T& top()
	{
		return st_.back();
	}

	size_t size()
	{
		return st_.size();
	}

	bool empty()
	{
		return st_.empty();
	}


private:
	vector<T> st_;

};


template<class T>
class Stack2 {
public:
	void push(const T&val)
	{
		st_.push_back(val);
	}

	void pop()
	{
		st_.pop_back();
	}

	T& top()
	{
		return st_.back();
	}

	size_t size()
	{
		return st_.size();
	}

	bool empty()
	{
		return st_.empty();
	}


private:
	list<T>st_;
};

void test()
{
	Stack2<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	st.push(0);
	st.pop();

	cout << "size:" << st.size() << endl;


	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;


	cout << "size:" << st.size() << endl;


}

int main()
{
	test();
	return 0;
}