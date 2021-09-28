#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void* my_memcpy(void* dest, void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = ++(char*)dest;
		src = ++(char*)src;
	}
	return ret;
}
void test()
{
	char str1[] = "123456";
	char str2[] = "654321";
	//my_memcpy(str1, str2, 6);
	//printf("%s\n", str1);	//654321
	
	my_memcpy(str2, str1, 6);
	printf("%s\n", str2);	//123456
}
int main()
{
	test();
	return 0;
}