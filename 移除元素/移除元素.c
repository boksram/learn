#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int numsSize = 8;
    int val = 2;
    int j = removeElement(nums, numsSize, val);
    for (int i = 0; i < j; i++)
    {
        printf("%d", nums[i]);
    }
    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    int* p1 = nums;
    int* p2 = nums;
    for (int i = 0; i < numsSize; i++)
    {
        if (*p1 != val)
        {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    return p2 - nums;
}