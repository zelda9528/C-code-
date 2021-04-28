#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A {
public:
	A()
	{
		++_a;
	}
	static int _a;
};

int A::_a = 0;

class B :public A {

};

int main()
{
	A a;
	B b;
	cout << a._a << endl;
	cout << b._a << endl;
	cout << &a._a << endl;
	cout << &b._a << endl;

	return 0;
}



//class Person {
//public:
//	Person(int i=1,int a=1):_id(i),_age(a)
//	{
//		cout << "Person()" << endl;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	Person& operator=(const Person& a)
//	{
//		if (this != &a)
//		{
//			_id = a._id;
//			_age = a._age;
//		}
//		cout << "Person operator=(const Person&)" << endl;
//		return *this;
//	}
//private:
//	int _id;
//	int _age;
//};
//class Student :public Person{
//public:
//	Student(int s = 01) :s_no(s)
//	{
//		cout << "Student()" << endl;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//	Student& operator=(const Student& a)
//	{
//		if (this != &a)
//		{
//			s_no = a.s_no;
//		}
//		cout << "Student operator=(const Student&)" << endl;
//		return *this;
//	}
//private:
//	int s_no;
//};
//
//int main()
//{
//	Student s1(1);
//	Student s2(2);
//	s1 = s2;
//
//	return 0;
//}//

//class A {
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//private:
//	int _a=1;
//};
//
//
//class B :public A {
//public:
//	void func()
//	{
//		cout << "B::func()" << endl;
//	}
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a=100;
//};
//
//
//int main()
//{
//	B b;
//	b.func();
//	b.Print();
//	return 0;
//}


//class Person{
//private:
//	int age=1;
//	long ID=610523;
//	string name="张三";
//	string sex="男";
//};
//
//
//class Student:public Person{
//private:
//	int stu_no;
//	int class_no;
//};
//
//void test()
//{
//	Person p;
//	Student s;
//	p = s;			//切片
//	Person * rp=&s;
//	Person & lp=s;
//	//s = p;		//父类对象不能赋值给子类对象
//
//	Person* pp;
//	pp = &p;
//	Student* ss;
//	ss = (Student*)pp; //基类指针强制类型转换赋值给派生类指针
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//
//class A {
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//	int a;
//};
//
//class B:public A 
//{
//public:
//	void func()
//	{
//		cout << "B::func()" << endl;
//	}
//	int a;
//};
//
//
//int main()
//{
//	B b;
//	b.func();
//	return 0;
//}
//
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		//cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << _num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};


//int main()
//{
//	Test();
//	return 0;
//}