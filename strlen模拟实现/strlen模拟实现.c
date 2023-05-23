#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
int my_strlen(char* arr)
{
	assert(arr != NULL);
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[10];
	scanf("%s", arr);
	printf("%d", my_strlen(arr));
	return 0;
}