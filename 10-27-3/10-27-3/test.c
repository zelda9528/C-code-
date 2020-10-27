#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void *my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);

	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = ++(char*)dest;
		src = ++(char*)src;
	}
	return ret;

}

int main()
{
	char str1[20] = "abcdef";
	char str2[10] = "zxcvbnm";
	my_memcpy(str1, str2, sizeof(str2));
	printf("%s ", str1);
	return 0;
}
