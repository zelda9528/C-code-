#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n;
	int a[10] = { 0 };
	int i;
	int sum = 0;
	int count = 0;
	for (n = 0; n <= 100000; ++n) { //遍历0-100000之间所有数字
		for (i = n; i; i /= 10) {
			a[count] = i % 10;  //用数组a[count]将每一位存起来,用count记下数字的位数
			++count;
		}
		for (i = 0; i < count; ++i) {
			sum += pow(a[i], count); //将数组中所存的数字的每一位进行对应的位数count次方并求和
		}
		if (n == sum) {
			printf("%d \n", n);
		}
		count = sum = 0; //强制将count与sum归0
	}
	return 0;
}