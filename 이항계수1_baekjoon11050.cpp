/*
	TITLE: BINOMIAL COEFFICIENT
	BAEKJOON 11050
	DATE: 2017-05-15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Combination(int n, int r)
{
	int result = 1;
	if (n == 0) result = 1;
	for (int i = 1; i <= r; i++)
	{
		result *= n;
		result /= i;
		n--;
	}
	printf("%d\n", result);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	Combination(a, b);
	return 0;
}