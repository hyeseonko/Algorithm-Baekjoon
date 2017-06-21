/*
	TITLE: NON-DECREASING DIGITS
	BAEKJOON 2688
	ACM-ICPC > Regionals > North America > Greater New York Region > 2010 Greater New York Programming Contest E
	CATEGORY: DP
	DATE: 2017-06-21

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long long dp[64][10] = { {1,1,1,1,1,1,1,1,1,1}, };
int main()
{
	int T; scanf("%d", &T); //testcase
	int MAX = 1;
	while (T--)
	{
		int N; scanf("%d", &N);
		unsigned long long sum = 0;
		for (int i = MAX; i < N; i++)
		{
			for (int j = 0; j <10; j++)
			{
				for (int k = 0; k <= j; k++)
				{
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
		for (int i = 0; i < 10; i++) sum += dp[N - 1][i];
		printf("%llu\n", sum);
		if (N > MAX) MAX = N;	
	}
	return 0;
}