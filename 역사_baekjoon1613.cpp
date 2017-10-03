/*
	TITLE: HISTORY
	BAEKJOON 1613
	CATEGORY: DFS, FLOYD WARSHALL
	DATE: 2017-10-03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[401][401];
int main()
{
	int N, K; scanf("%d %d", &N, &K);
	while (K--)
	{
		int from, to; scanf("%d %d", &from, &to);
		arr[from][to] = 1;
		arr[to][from] = -1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == -1)
			{
				for (int k = 1; k <= N; k++)
				{
					if (arr[i][k] == 1&&arr[j][k]==0)
					{
						arr[j][k] = 1;
					}
				}
			}
		}



	}
	int S; scanf("%d", &S);
	while (S--)
	{
		int from, to; scanf("%d %d", &from, &to);
		if (arr[from][to] == 1) puts("-1");
		else if (arr[from][to] == -1) puts("1");
		else puts("0");
	}



	return 0;
}