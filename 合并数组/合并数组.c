void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* p1 = nums1 + m - 1;
    int* p2 = nums2 + n - 1;
    int* end = nums1 + m + n - 1;
    while ((p1 - nums1 + 1) && (p2 - nums2 + 1))
    {
        if (*p1 < *p2)
        {
            *end = *p2;
            p2--;
            end--;
        }
        else
        {
            *end = *p1;
            p1--;
            end--;
        }
    }
    if (nums1 > p1)
    {
        while (p2 - nums2 + 1)
        {
            *end = *p2;
            p2--;
            end--;
        }
    }
}