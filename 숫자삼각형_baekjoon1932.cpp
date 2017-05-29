/*
	TITLE: THE TRIANGLE
	BAEKJOON 1932
	IOI 1994 #01
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-29

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[500][500];
int map[500][500];
int bigger(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int N; scanf("%d", &N); // the size of the triangle
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	dp[0][0] = map[0][0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0] + map[i][0];
		dp[i][i] = dp[i - 1][i - 1] + map[i][i];
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = map[i][j] + bigger(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int result = dp[N - 1][0];
	for (int i = 1; i <= N - 1; i++)
	{
		if (result < dp[N - 1][i]) result = dp[N - 1][i];
	}
	printf("%d\n", result);
	return 0;
}
/* HOW I solved this */
/*
	using Dynamic Programming
	dp[n][0]=dp[n-1][0]+map[n][0];
	dp[n][1]=map[n][1]+bigger(dp[n-1][0],dp[n-1][1]);
	dp[n][2]=map[n][2]+bigger(dp[n-1][1]+dp[n-1][2]);
	....
	dp[n][n-1]=map[n][n-1]+bigger(dp[n-1][n-1],dp[n-1][n-2]);
	dp[n][n]=map[n][n]+dp[n-1][n-1];
	bigger of dp[n][0].....dp[n][n] is the answer!
*/