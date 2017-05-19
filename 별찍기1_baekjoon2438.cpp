/*
	TITLE: MAKING STARS
	BAEKJOON 2438
	DATE: 2017-05-19

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for(int j=1;j<=i;j++)	printf("*");
		printf("\n");
	}
	return 0;
}