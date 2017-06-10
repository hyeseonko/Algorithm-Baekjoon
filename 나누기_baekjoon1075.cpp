/*
	TITLE: DIVISION
	BAEKJOON 1075
	CATEGORY: MATH
	DATE: 2017-06-10

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N, F; scanf("%d", &N); scanf("%d", &F);
	for (int i = 0; i < 100; i++)
	{
		if (((N / 100)*100 + i) % F == 0) {
			if (i < 10) printf("0%d\n", i);
			else printf("%d\n", i);
			break;
		}
	}
	return 0;
}