#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<map>
using namespace std;
////C++11数据初始化方式
//
//struct A {
//	 int _a;
//	/*explicit*/ A(int a):_a(a)
//	{}
//
//	A(int a, int b, int c) :_a(a)
//	{}
//
//};
//
//template<class T>
//class Vector{
//private:
//	T _a;
//	size_t _capacity;
//	size_t _size;
//
//public:
//	Vector(int a = 1):_a(a),_capacity(10),_size(1)
//	{}
//	Vector(init):_a
//
//};
//
//
//
//void test()
//{
//	A a1(100);
//	A a4 = 100;	//单参构造的隐式类型转换
//	//C++11种支持内置类型 自定义类型的列表初始化方式
//	A a2{ 100 };
//	A a3 = { 100 };
//	A a5 = { 1,2,3 };
//
//	vector<int> v1(1);
//	vector<int> v2(10,0);
//	vector<int> v3 = { 1,2,3,4,5 };
//	vector<int> v4{ 1,2,3,4,5,6 };
//
//	set<int> s{ 1,2,3,4,5,1,2,3,4,5 };
//	map<int, int> m{ {1,100},{2,200} ,{3,300} };
//
//	pair<int, int> p = { 1,3 };
//
//	//自定义容器类如果需要使用列表初始化
//	//需要定义一个构造函数，参数为initializer_list 对象（初始化列表）
//
//	int arr[]{ 1,2,2,2 };
//
//}
//
//
//class A {
//public:
//	A(int a)
//	{}
//
//	//default：让编译器显式地生成一个默认的构造函数
//	A() = default;
//
//	A(const A&) = default;
//
//	A& operator=(const A&) = default;
//};
//
//class B {
//public:
//	B(){}
//	//成员函数如果被定义为delete函数，表示函数不能再被使用
//	//例如：防止拷贝，防止赋值
//	B(const B&) = delete;
//
//	B& operator=(const B&) = delete;
//};
//
//void test2()
//{
//	B b;
//	//B b2 = b;
//	//B b2(b);
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//C++11左值引用、右值引用
int fun(int a) { return a; }

void test()
{
	//左值引用：可以引用左值也可以引用右值--引用右值要加const关键字
	int a = 10;
	int &ra = a;
	const int &ri = 10;
	const int &ri2 = fun(a);


	//右值引用&&：只能引用右值
	int &&rri = 10;
	int &&rri2 = fun(a);
}

int main()
{
	test();
	return 0;
}