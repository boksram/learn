#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int left = 0;
	int right = 9;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	while (left < right)
	{
		while (left < right && arr[left] % 2 == 1)
		{
			left++;
		}
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int j = arr[left];
			arr[left] = arr[right];
			arr[right] = j;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}