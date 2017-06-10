/*
	TITLE: SKOCIMIS
	BAEKJOON 2965
	COCI 2008/2009 > Contest #1
	CATEGORY: MATHEMATICS
	DATE: 2017-06-10

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A, B, C; scanf("%d%d%d", &A, &B, &C);
	if (B - A > C - B) printf("%d\n", B - A - 1);
	else printf("%d\n", C - B - 1);
	return 0;
}