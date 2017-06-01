/*
	TITLE: STAIRS
	BAEKJOON 2579
	CATEGORY: DP
	DATE: 2017-06-01

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define bigger(a,b) (a>b?a:b)
int stairs[300];
int dp[300];

int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &stairs[i]);
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = stairs[2] + bigger(stairs[0], stairs[1]);
	for (int i = 3; i < N; i++)
	{
		dp[i] = stairs[i] + bigger(dp[i - 2], dp[i - 3] + stairs[i - 1]);
	}
	printf("%d\n", dp[N - 1]);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	USING DYNAMIC PROGRAMMING
	THE TRICKY PART WAS CONSIDERING 1-1-1 STEP.
	To solved this, I considered not only in two consecutive ones, but three consecutives.
	
	To reach dp[x], there are two ways to go there
	1) dp[x-2] + two steps = dp[x]
	2) dp[x-3] + two steps + one step = dp[x]
	The reason why I don't add dp[x-1] is I might calculate the case of 1-1-1 steps.
	So, I need to consider from the x-3 cases. 

*/