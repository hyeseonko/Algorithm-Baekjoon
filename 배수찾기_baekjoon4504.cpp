/*
	TITLE: FINDING A MULTIPLE
	BAEKJOON 4504
	CATEGORY: MATH
	DATE: 2017-08-05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	while (1)
	{
		int num; scanf("%d", &num);
		if (num == 0) break;
		if (num%N == 0) printf("%d is a multiple of %d.\n", num, N);
		else printf("%d is NOT a multiple of %d.\n", num, N);
	}
	return 0;
}