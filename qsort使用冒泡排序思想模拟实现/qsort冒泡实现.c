#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char name[10];
	int age;
};

int int_cmp(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}

int float_cmp(const void* x, const void* y)
{
	return (int)(*(float*)x - *(float*)y);
}

int char_cmp(const void* x, const void* y)
{
	return *(char*)x - *(char*)y;
}

int stu_cmp_byname(const void* x, const void* y)
{
	return strcmp(((struct stu*)x)->name , ((struct stu*)y)->name);
}

int stu_cmp_byage(const void*  x, const void* y)
{
	return ((struct stu*)x)->age - ((struct stu*)y)->age;
}

void swap(char* x, char* y, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		char temp = *(x + i);
		*(x + i) = *(y + i);
		*(y + i) = temp;
	}
}

void bubble_sort(void* base, int sz, int size, int (*p)(const void* p1, const void* p2))
{
	int i, j, k;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (p((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

int main()
{
	int arr1[5] = { 4,5,1,3,2 };
	float arr2[5] = { 3.14,2.18,0.00,4.32,1.58 };
	char arr3[5] = { 'c','a','e','d','b' };
	struct stu arr4[3] = {{"zhangsan",18},{"lisi",24},{"wangwu",20}};
	int i;
	bubble_sort(arr1, 5, 4, int_cmp);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	bubble_sort(arr2, 5, 4, float_cmp);
	for (i = 0; i < 5; i++)
	{
		printf("%.2f ", arr2[i]);
	}
	printf("\n");
	bubble_sort(arr3, 5, 1, char_cmp);
	for (i = 0; i < 5; i++)
	{
		printf("%c ", arr3[i]);
	}
	printf("\n");
	bubble_sort(arr4, 3, sizeof(arr4[0]), stu_cmp_byname);
	for (i = 0; i < 3; i++)
	{
		printf("%s ", arr4[i].name);
	}
	printf("\n");
	bubble_sort(arr4, 3, sizeof(arr4[0]), stu_cmp_byage);
	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr4[i].age);
	}
	printf("\n");
	return 0;
}