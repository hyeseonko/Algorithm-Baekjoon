/*
	TITLE: SUM UP USING 1,2,3
	BAEKJOON 9095
	DAEJEON 2001 PC
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[10] = { 1,2,4, };
int main()
{
	int T; scanf("%d", &T); //Testcase
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 3; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n - 1]);
	}
	return 0;
}
/* How I solved this */
/*
	Using Dynamic programming
	the number N is comprised with numbers ending with either 1, 2, or 3.
	so, Nth number is a sum of (n-1)th number + (n-2)th number + (n-3)th number
	since (n-1) + 1 = n, (n-2) + 2 =n, (n-3) + 3 = n.
*/