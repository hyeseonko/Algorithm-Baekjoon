/*
	TITLE: 2 x N TILING 2
	BAEKJOON 11727
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-29

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[1000] = { 1,3, };
int main()
{
	int N; scanf("%d", &N);
	for (int i = 2; i < N; i++)
	{
		dp[i] = (dp[i - 1] % 10007 + (2*dp[i - 2]) % 10007) % 10007;
	}
	printf("%d\n", dp[N - 1]);
	return 0;
}

/* How I solved this */
/*
	Using Dynamic programming
	This sequence is same as dp[n]=dp[n-1]+2*dp[n-2] since
	(n-1) + 2x1 long tile = n
	(n-2) + 1X2 two tiles = n
	(n-2) + 2x2 one tile = n
*/