/*
	TITLE: THE BIGGEST SQUARE
	BAEKJOON 1915
	CATEGORY: DP
	DATE: 2017-08-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define smaller(a,b) a<b?a:b
int arr[1001][1001];
int dp[1001][1001];
int MAX;
int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == 1) {
			dp[i][0] = 1;
			MAX = 1;
		}
		else dp[i][0] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		if (arr[0][i] == 1) { 
			dp[0][i] = 1; 
			MAX = 1; 
		}
		else dp[0][i] = 0;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{		
			if (arr[i][j] == 1)
			{
				dp[i][j] = 1;
				dp[i][j] += smaller(smaller(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			}
			if (MAX < dp[i][j]) MAX = dp[i][j];
		}
	}
	printf("%d\n", MAX*MAX); return 0;
}
/* METHOD */
/*
	DP[i][j]= (0,0)���� (i,j)���� ����� ���簢���߿� ���� ū �� ����
	���� (i,j)�� 1�ΰ�� : dp[i][j]=min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1])+1 // idea very good
	���� (i,j)�� 0�ΰ��: dp[i][j]=0;

*/