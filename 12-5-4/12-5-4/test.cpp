#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int count = 0;//换法
	int temp;
	int m = 100;//总钱数
	int a = 1;//1元面值
	int b = 2;//2元面值
	int c = 5;//5元面值
	//a, b, c的值还可以是10,20,50
	for (int i = 0; i <= m / b; ++i) {
		for (int j = 0; j <= m / c; ++j) {
			temp = m - (b * i + c * j);
			if (temp >= 0 && temp % a == 0) {//只要2元和5元的总和加起来不大于100,剩下的都换1元
				++count;
			}
		}
	}
	cout << "换法有" << count << "种\n";
	return 0;
}