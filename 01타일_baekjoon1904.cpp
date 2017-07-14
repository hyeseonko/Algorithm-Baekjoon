/*
	TITLE: 01 TILE
	BAEKJOON 1904
	CATEGORY: DP
	DATE: 2017-07-14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[1000000] = { 1,2,3,5, };
int main()
{
	int N; scanf("%d", &N);
	for (int i = 4; i < N; i++)
	{
		dp[i] = (dp[i - 1]+ dp[i - 2])%15746;
	}
	printf("%d\n", dp[N - 1]); return 0;
}