/*
	TITLE: SUM OF SQUARES
	BAEKJOON 1699
	Asia Regional - Daejeon Nationalwide Internet Competition 2007 E
	CATEGORY: DP
	DATE: 2017-09-08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int dp[100001];

int main()
{
	int N; scanf("%d", &N);
	for (int i = 1; i <= sqrt(N); i++)
	{
		dp[i*i] = 1;
	}
	if (dp[N] == 1) 
	{
		puts("1"); return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		if (dp[i] == 1) continue;
		int min = N;
		for (int j = 1; j <= (i/ 2); j++)
		{
			int temp = dp[j] + dp[i - j];
			if (temp < min)
			{
				min = temp;
				if (min == 2) break;
			}
		}
		dp[i] = min;
	}
	printf("%d\n", dp[N]);
	return 0;
}