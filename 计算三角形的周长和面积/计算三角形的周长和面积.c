#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    float d = a + b + c;
    float p = d / 2;
    printf("circumference=%.2f area=%.2f", d, sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}
