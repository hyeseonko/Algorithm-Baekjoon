/*
	TITLE: COIN 1
	BAEKJOON 2293
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-07-18
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int coin[101];
int dp[10001];
int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)		scanf("%d", &coin[i]);
	dp[0] = 1;
	for (int i = 1; i<=N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[K]);
	return 0;
}