/*
	TITLE: SUM OF DIFFERENT NATURAL NUMBERS
	BAEKJOON 9764
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-08-02
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[2001][1000];
int main()
{
	int T; scanf("%d", &T); //testcase
	int max = 1;
	while (T--)
	{
		int num; scanf("%d", &num);
		for (int i = max; i <= num; i++)
		{
			for (int j = 1; j <= (i - 1) / 2; j++)
			{
				dp[i][j] = 1;
				int temp = j + 1;
				while ((i - j) > 2 * temp)
				{
					dp[i][j] += (dp[i - j][temp]) % 100999;
					temp++;
				}
			}
		}
		int sum = 1;
		for (int i = 1; i <= (num - 1) / 2; i++)
		{
			sum += (dp[num][i]) % 100999;
		}
		printf("%d\n", sum % 100999);
		if (num > max) max = num;
	}
	return 0;
}
/* HOW TO SOLVE */
/*
	USING DYNAMIC PROGRAMMING

	dp[10][1] : = 1 + 9, 1 + 3 + 6... "10을 만드는데 1을 포함하고 만듬"
	dp[10][1] = dp[9][2] + dp[9][3] + dp[9][4]
	dp[10][2] = dp[8][2] + dp[8][3]
	...
	dp[10][4] : = 4 + 6 끝!
	
	ANSWER: dp[10][1]+...dp[10][4] + 1

*/