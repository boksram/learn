#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void* my_memcpy(void* dest, void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return dest;
}
int main()
{
	char arr[10] = "abcdef";
	my_memcpy(arr, arr + 2, 2);
	printf("%s", arr);
	return 0;
}