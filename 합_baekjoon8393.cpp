/*
	TITLE: SUM
	BAEKJOON 8393
	ALGORITHMIC ENGAGEMENTS PA 2006 #01
	DATE: 2017-05-19
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	printf("%d\n", N*(N + 1) / 2);
	return 0;
}
