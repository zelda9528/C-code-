#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
 
void *my_memmove(void* dest, const void*src, size_t count)
{
	char*ret = (char*)dest;

	if (dest <= src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;

}
int main()
{
	char str1[20] = "xxxxxxxxxxxxx";
	char str2[10] = "zxcvbnm";
	my_memmove(str1,str2,sizeof(str2));
	printf("%s\n", str1);
	return 0;
}