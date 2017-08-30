/*
	TITLE: CONSECUTIVE SUM
	BAEKJOON 1912
	CATEGORY: DP
	DATE: 2017-08-30

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define bigger(a,b) (a>b?a:b)
int arr[100000];
int dp[100000][3];
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[0][0] = dp[0][1] =dp[0][2]=arr[0];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = arr[i];
		dp[i][1] = bigger(dp[i - 1][0], dp[i - 1][1]) + arr[i];
		dp[i][2] = bigger(bigger(dp[i - 1][0], dp[i - 1][1]), dp[i- 1][2]);
	}
	int result = bigger(bigger(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	printf("%d\n", result);	return 0;
}
/* METHOD */
/*
	DP[N][0] = 새로운 동전[N]
	DP[N][1] = 그전의 합 중 젤 큰놈[N-1] + 새로운 동전[N]
	DP[N][2] = 그전의 합 그대로[N-1]

*/