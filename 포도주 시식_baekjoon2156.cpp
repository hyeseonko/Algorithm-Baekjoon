/*
	TITLE: DRINKING WINE
	BAEKJOON 2156
	CATEGORY: DP
	DATE: 2017-06-02
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define bigger(a,b) ((a>b)?a:b)
int wine[10000];
int dp[10000];
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &wine[i]);
	dp[0] = wine[0]; dp[1] = wine[0] + wine[1];
	dp[2] = bigger(bigger(dp[1], dp[0] + wine[2]), wine[1] + wine[2]);
	for (int i = 3; i < N; i++)
		dp[i] = bigger(bigger(dp[i - 1], dp[i - 2] + wine[i]), dp[i - 3] + wine[i] + wine[i - 1]);
	printf("%d\n", dp[N - 1]);	return 0;
}
/* HOW I SOLVED THIS */
/*
	using dynamic programming
	let dp[x]=the largst amount of wine I drink up to x glasses but not three consecutives.
	dp[x]=biggest among dp[x-1], dp[x-2]+wine[x], dp[x-3]+wine[x]+wine[x-1]
*/