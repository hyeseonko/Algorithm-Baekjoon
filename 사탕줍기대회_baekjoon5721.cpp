/*
	TITLE: Candy Distribution
	BAEKJOON 5721
	South America Regional Contests 2008 C번
	CATEGORY: DP
	DATE: 2017-10-10
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h> //memset
using namespace std;

int dp[2][100000];
vector <int> v;
int MAX[100000];
int bigger(int m, int n)
{
	if (m > n) return m;
	else return n;
}
int main(){
	while (1)	{
		int M, N; scanf("%d %d", &M, &N);
		if (M == 0 && N == 0) return 0;
		for (int i = 0; i < M*N; i++)
		{
			int temp; scanf("%d", &temp);
			v.push_back(temp);
			if (i /N == 0) // 첫번째 줄
			{
				if (i%N <= 1)		dp[0][i%N] = v[i];
				else if (i%N == 2)	dp[0][2] = v[i] + v[i-2];
				else				dp[0][i%N] = v[i] + bigger(dp[0][i%N - 2], dp[0][i%N - 3]);
				MAX[0] = dp[0][N - 1];
				if (N >= 2 && dp[0][N - 2] > dp[0][N - 1]) MAX[0] = dp[0][N - 2];
			}

			else if (i / N== 1) // 두번째 줄
			{
				if (i%N <= 1)		dp[1][i%N] = v[i];
				else if (i%N == 2)	dp[1][2] = v[i] + v[i-2];
				else				dp[1][i%N] = v[i] + bigger(dp[1][i%N - 2], dp[1][i%N - 3]);
				MAX[1] = dp[1][N - 1];
				if (N >= 2 && dp[1][N - 2] > dp[1][N - 1]) MAX[1] = dp[1][N - 2];
			}

			else // Inner Node
			{
				if (i%N <= 1) dp[(i / N) % 2][i%N] = bigger(MAX[(i / N)-2], MAX[(i/ N)-3]) + v[i];
				else if (i%N == 2)
				{
					dp[(i / N) % 2][2] = v[i] + dp[(i / N) % 2][0];
				}
				else
				{
					dp[(i / N) % 2][i%N] = v[i] + bigger(dp[(i / N) % 2][i%N-2], dp[(i / N) % 2][i%N - 3]);
				}
				MAX[(i / N)] = dp[(i / N) % 2][N - 1];
				if (N >= 2 && dp[(i / N) % 2][N - 2] > dp[(i / N) % 2][N - 1]) MAX[i / N] = dp[(i / N) % 2][N - 2];
			}
			//printf("dp[%d][%d]=%d MAX[%d]=%d MAX[%d]=%d\n", (i / N) % 2, i%N, dp[(i / N) % 2][i%N],i/ N, MAX[i/ N], i/ N, MAX[i/ N]);
		}
		if (M == 1) printf("%d\n", MAX[0]);
		else printf("%d\n", bigger(MAX[M-1], MAX[M-2]));
		memset(dp, 0, sizeof(dp));
		v.clear();		
	}
	return 0;
}