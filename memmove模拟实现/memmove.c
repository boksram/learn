#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void* my_memmove(void* dest, void* src, size_t num)
{
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	char arr1[10] = "abcdef";
	my_memmove(arr1 + 2, arr1, 2);
	printf("%s", arr1);
	return 0;
}