/*
	TITLE: EASY STAIRS
	BAEKJOON 10844
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-06-01
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[100][10] = { 0,1,1,1,1,1,1,1,1,1, };
int main()
{
	int N; scanf("%d", &N); // input
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000) % 1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[N - 1][i];
		sum %= 1000000000;
	}
	printf("%d\n", sum);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	USING Dynamic programming
	LET dp[x][y] := the number ending with y with the length x

	dp[x][0]=dp[x-1][1]
	dp[x][1]=dp[x-1][0]+dp[x-1][2]
	dp[x][2]=dp[x-1][1]+dp[x-1][3]
	....
	dp[x][8]=dp[x-1][7]+dp[x-1][9]
	dp[x][9]=dp[x-1][8]

*/