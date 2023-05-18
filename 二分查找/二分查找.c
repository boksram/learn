#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	scanf("%d", &i);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (i < arr[middle])
		{
			right = middle - 1;
		}
		if (i > arr[middle])
		{
			left = middle + 1;
		}
		if (i == arr[middle])
		{
			printf("找到了，下标是%d", middle);
			break;
		}
		if (left >= right)
		{
			printf("找不到");
		}
	}
	return 0;
}