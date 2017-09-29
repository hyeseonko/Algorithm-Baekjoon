/*
	TITLE: SUMMATION OF POWER OF TWO
	BAEKJOON 2410
	CATEGORY: DP
	DATE: 2017-09-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long dp[1000001] = { 1, };

int main()
{
	int N; scanf("%d", &N);
	for (int i = 1; i <=N; i *= 2)
	{
		for (int j = i; j <= N; j++)
		{
			dp[j] = (dp[j] + dp[j - i])%1000000000;
		}
	}
	printf("%lld\n", dp[N]);
	return 0;
}