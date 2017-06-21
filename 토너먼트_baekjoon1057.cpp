/*
	TITLE: TOURNAMENT
	BAEKJOON 1057
	CATEGORY: SIMULATION
	DATE: 2017-06-22
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define bigger(a,b) a>b?a:b
#define smaller(a,b) a>b?b:a

int main()
{
	int N, A, B; scanf("%d %d %d", &N, &A, &B);
	int x = smaller(A, B);
	int y = bigger(A, B);
	int count = 1;
	while (!(y - x == 1 && y % 2 == 0))
	{
		x = (x + 1) / 2;
		y = (y + 1) / 2;
		count++;
	}
	printf("%d\n", count);	return 0;
}