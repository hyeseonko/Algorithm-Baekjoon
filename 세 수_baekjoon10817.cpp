/*
	TITLE: THREE NUMBERS
	BAEKJOON 10817
	CATEGORY: MATH
	DATE: 2017-06-19

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A, B, C; scanf("%d %d %d", &A, &B, &C);
	if (A > B)
	{
		if (C > A) printf("%d\n", A);
		else if (C < B) printf("%d\n", B);
		else printf("%d\n", C);
	}
	else
	{
		if (C > B) printf("%d\n", B);
		else if (C < A) printf("%d\n", A);
		else printf("%d\n", C);
	}
	return 0;
}