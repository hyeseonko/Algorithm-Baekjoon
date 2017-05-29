/*
	TITLE: 2 X N Tiling
	BAEKJOON 11726
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[1000] = { 1,2, };
int main()
{
	int N; scanf("%d", &N);
	for (int i = 2; i < N; i++)
	{
		dp[i] = ((dp[i - 1]%10007) + (dp[i - 2]%10007))%10007;
	}
	printf("%d\n", dp[N - 1]);
	return 0;
}
/* how I solved this */
/*
	Nth block is comprised with 2X1 block and (n-1) block + 1X2 two blocks and (n-2) blocks
	So, this is same as fibonacci sequence but with different initial conditions f1=1, f2=2;
	
*/