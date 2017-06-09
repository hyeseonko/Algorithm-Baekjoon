/*
	TITLE: INCREASING NUMBER
	BAEKJOON 11057
	CATEGORY: DP
	DATE: 2017-06-09

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[1000][10] = { {1,1,1,1,1,1,1,1,1,1}, };
int main()
{
	int N; scanf("%d", &N);
	
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[N - 1][i];
		sum %= 10007;
	}

	printf("%d\n", sum);	return 0;
}