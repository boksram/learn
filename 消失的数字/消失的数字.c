#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int missingnumber(int* numbers, int numbersize)
{
	int ret = 0;
	int i = 0;
	for (i = 0; i < numbersize; i++)
	{
		ret ^= numbers[i];
	}
	for (i = 0; i < numbersize + 1; i++)
	{
		ret ^= i;
	}
	return ret;
}
int main()
{
	int arr[10] = { 0,1,2,3,4,6,7,8,9,10 };
	printf("%d", missingnumber(arr, 10));
	return 0;
}
