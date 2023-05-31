#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char killer = 'A';
	for (; killer <= 'D'; killer++)
	{
		if (((killer!='A')+(killer=='C')+(killer=='D') + (killer != 'D'))==3)
			printf("%c", killer);
	}
	return 0;
}