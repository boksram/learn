#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,1,2,3,4,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	int i = 0;
	int n = 0;
	int dog = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	for (i = 0; i < sz; i++)
	{
		if (ret >> i & 1 == 1)
		{
			n = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (arr[i] >> n & 1 == 1)
			dog ^= arr[i];
	}
	printf("dog1=%d\ndog2=%d", dog, ret ^ dog);
	return 0;
}