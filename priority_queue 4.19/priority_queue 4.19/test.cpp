#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<queue>

using namespace std;


class A {
public:
	A(int a = 1):a_(a)
	{}
	bool operator>(const A& a)const
	{
		return a_ > a.a_;
	}
	bool operator<(const A& a)const
	{
		return a_ < a.a_;
	}

private:
	int a_;
};


void test()
{
	//优先队列存放自定义类型：需要自定义类型支持比较操作  '<' 或者 '>'
	priority_queue<A>pq;
	pq.push(A(1));
	pq.push(A(2));
	pq.push(A(0));
	pq.push(A(9));
	pq.push(A(7));
}

int main()
{
	test();
	return 0;
}