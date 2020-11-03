#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>


char* my_strcat(char* dest, const char* src,size_t num)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	//1. 找目的地空间的'\0'
	while (*dest)
	{
		dest++;
	}
	//2. 拷贝数据

	for (int i = 0; i < num; i++)
	{
		*dest++ = *src++;
	}
	return ret;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	char arr1[20] = "hello";

	printf("%s\n", my_strcat(arr1, "world",num));
	return 0;
}