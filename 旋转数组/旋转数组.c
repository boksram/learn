#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void exchange(int* left,int* right)
{
	while (left < right)
	{
		int temp = 0;
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
int main()
{
	int n;
	int arr[10];
	scanf("%d%d%d%d%d%d%d%d%d%d",&arr[0],&arr[1],&arr[2],&arr[3], &arr[4], &arr[5], &arr[6], &arr[7],&arr[8],&arr[9]);
	scanf("%d", &n);
	exchange(arr, arr + n % 10);
	exchange(arr + n % 10 + 1, arr + 9);
	exchange(arr, arr + 9);
	for (n = 0; n < 10; n++)
	{
		printf("%d ", arr[n]);
	}
	return 0;
}