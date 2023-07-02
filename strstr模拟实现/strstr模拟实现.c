#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
//#include <windows.h>

char* mystrstr(char* p1, char* p2)
{
	assert(p1 != NULL && p2 != NULL);
	char* s1 = p1;
	char* s2 = p2;
	char* cur = p1;
	if (*p2 == '\0')
		return p1;
	while (*cur)
	{
		s1 = cur;
		s2 = p2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return cur;
		cur++;
	}
	if (*cur == '\0')
		return NULL;
}

int main()
{
	char* p1 = "abbcdef";
	char* p2 = "bbc";
	char* ret = mystrstr(p1, p2);
	if (ret == NULL)
		printf("ÕÒ²»µ½×Ó´®\n");
	else
		printf("%s\n", ret);

}