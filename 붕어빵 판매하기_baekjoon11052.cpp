/*
	TITLE: SELLING A FISH-SHAPED BUN
	BAEKJOON 11052
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define bigger(a,b) ((a>b)?a:b)
int dp[1001];
int main()
{
	int N; scanf("%d", &N); //the number of fish-shaped bun
	int price[1001] = { 0, };
	for (int i = 1; i <= N; i++) scanf("%d", &price[i]);
	dp[1] = price[1];
	for (int i = 2; i <= N; i++)
	{
		int result = price[i];
		for (int j = 1; j < i; j++)
		{
			result = bigger(result, dp[i - j] + price[j]);
		}
		dp[i] = result;
	}
	printf("%d\n", dp[N]);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	using dynamic programming
	
	dp[x] = the answer I want to get
	price[x] = The bun set of x sells at this price 
	dp[x] = biggest of (dp[x-1]+price[1], dp[x-2]+price[2], ..., dp[0] + price[0]+price[x])

*/