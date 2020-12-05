#define _CRT_SECURE_NO_WARNINGS 1
//sum.cpp
#include<iostream>                      
using namespace std;                    

										
										
//int main()                              //主函数   
//{
//	int x, y, sum;                        //定义三个整型变量x，y，sum
//	cin >> x;                             //从键盘输入x
//	cin >> y;                             //从键盘输入y
//	sum = x + y;                            //将x与y和赋给sum  
//	cout << "x+y=" << sum << endl;            //输出两个整数和sum
//	return 0;                           //程序结束，返回0
//}


int main()
{
	int a = 1;
    int const T1=a+a;
    int const T2=T1-T1;
	cout << "T2 is " << T2 ;
	return 0;

}
