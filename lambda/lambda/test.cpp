#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

void test()
{
	//lambda表达式：[捕捉列表](参数列表)（mutable可选）->返回值类型{函数体}
	//捕捉列表：捕获父作用域中的变量
	int a = 10;
	int b = 20;
	[a, b] {return a + b; };
	
	//参数列表：类似于函数地参数列表
	[a, b](int c) {return a + b + c; };

	//返回值：类似于函数返回值
	[a, b](int c)->int {return a + b + c; };

	//函数体：类似于函数，可以有多句指令
	//mutable：将捕捉列表中变量的属性修改为非const，默认是const
	[a, b](int c)mutable-> int {a = 10; b = 200; };

	//参数列表和返回值可以省略
	[] {};	//合法

	//返回值一般不用写，编译器会自动推导
	[a, b] {return a + b; };

	//如果使用了mutable，即使参数列表为空也需要显式地写出来
	[a, b]()mutable{return a + b; };

	//以上只是lambda表达式的定义，无法使用，要获取其值后才能使用

	auto f=[a, b](int c) {return a + b + c; };
	int e = f(10);

	//如果参数比较多可以用以下方式简单的进行接受
	//[=]：以值的形式捕捉所有参数
	auto f2 = [=]() {return a + b; };

	//[&]：以引用的形式捕捉所有参数
	auto f3 = [&]() {a = 1; b = 2; };
	f3(); 

	//[=,& x]：x以引用形式捕捉，其他的以值地形式捕捉
	//[&,x]：x以值的形式捕捉，其他的以引用形式捕捉
	//错误的捕捉方式[=,x]

	//[this]：捕捉成员函数中的this指针
}

struct A {
	void fun(int a)
	{
		auto f=[this]() {return _a; };
	}
	int _a;
};
//void test()
//{
//	int array[]{ 4,5,6,3,2,1,7,8,9, };
//	sort(array, array + sizeof(array) / sizeof(array[0]));
//	sort(array, array + sizeof(array) / sizeof(array[0]),greater<int>());
//
//}
//
//struct A {
//public:
//	A(int age=1,int id=1,string name="")
//		:_age(age)
//		,_id(id)
//		,_name(name)
//	{}
//	int _age;
//	int _id;
//	string _name;
//	bool operator<(const A& a)
//	{
//		return _age < a._age;
//	}
//
//};
//
//struct Less {
//	bool operator()(const A& a, const A& b)
//	{
//		return a._id > b._id;
//	}
//};
//
//void test()
//{
//	vector<A> a = { {18,1,"zhangsan"},{17,2,"lisi"},{22,3,"wangwu"} };
//	sort(a.begin(), a.end());
//
//	sort(a.begin(), a.end(),Less());
//
//
//	//lambda表达式
//	sort(a.begin(), a.end(), 
//		[](const A&a, const A& b)
//	{return a._name > b._name; });
//
//
//}

int main()
{
	test();
	return 0;
} 