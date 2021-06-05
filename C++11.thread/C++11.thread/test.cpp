#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
unsigned long sum = 0L;
void fun(size_t num) {
	for (size_t i = 0; i < num; ++i)
		sum++;
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}


//atomic_long sum{ 0 };	//atomic_long为原子类型
//
//void fun(size_t num) {
//	for (size_t i = 0; i < num; ++i)
//		sum++; // 原子操作
//}
//int main()
//{
//	cout << "Before joining, sum = " << sum << std::endl;
//	thread t1(fun, 1000000);
//	thread t2(fun, 1000000);
//	t1.join();
//	t2.join();
//
//	cout << "After joining, sum = " << sum << std::endl;
//	return 0;
//}

//#include<thread>
//#include<iostream>
//#include<atomic>
//
//using namespace std;
//
//void fun1()
//{
//	cout << "t1" << endl;
//}
//
//struct fun2 {
//	void operator()()
//	{
//		cout << "t2" << endl;
//	}
//};
//
//void fun3(int& a)
//{
//	a += 10;
//}
//
//
//int main()
//{
//	// 线程函数为函数指针
//	thread t1(fun1);
//
//	// 线程函数为函数对象
//	fun2 a;
//	thread t2(a);
//
//	// 线程函数为lambda表达式
//	thread t3([] {cout << "t3" << endl; });
//
//	//线程等待，回收资源
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}


//int main()
//{
//	thread t;
//	cout << t.get_id() << endl;
//	return 0;
//}