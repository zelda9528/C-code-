#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

void left_move(char * src, int k)
{
	int len = strlen(src);
	int pos = k % len; //断开位置的下标
	char tmp[256] = { 0 }; //更准确的话可以选择malloc len + 1个字节的空间来做这个tmp

	strcpy(tmp, src + pos); //先将后面的全部拷过来
	strncat(tmp, src, pos); //然后将前面几个接上
	strcpy(src, tmp); //最后拷回去
}
int main()
{
	int k = 0;
	scanf("%d", &k);
	char arr[] = "abcdef";
	printf("%s\n", arr);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}