#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//char my_strlen(char* arr)
//{
//	char* start = arr;
//	char* end = arr;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end-start;
//}
int main()
{
	int i = 0;
	char arr[] = "abcdefghij";
	i = my_strlen(arr);
	printf("%d\n", i);
	return 0;
}