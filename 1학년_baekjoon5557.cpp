/*
	TITLE: A FIRST GRADER
	BAEKJOON 5557
	JOI 2011 PRE-04
	CATEGORY: DP
	DATE: 2017-09-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100];
unsigned long long dp[21][99];
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[arr[0]][0] = 1;
	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[j][i] >= 1)
			{
				if (j + arr[i + 1] <= 20) dp[j + arr[i + 1]][i + 1] += dp[j][i];
				if (j - arr[i + 1] >= 0) dp[j - arr[i + 1]][i + 1] += dp[j][i];
			}
		}
	}
	printf("%lld\n", dp[arr[N - 1]][N - 2]);

	return 0;
}

/* ERROR: MEMEORY EXPLOSION
#include <queue>
using namespace std;
queue <pair<int,int>> q;
int arr[100];
unsigned long long result;
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	q.push({ arr[0],0 });

	while (!q.empty())
	{
		int qx = q.front().first;
		int qc = q.front().second;
		q.pop();
		if (qc == N - 2 && qx == arr[N - 1]) result++;
		if (qc < N - 2)
		{
			if (qx + arr[qc + 1] <= 20) q.push({ qx + arr[qc + 1], qc + 1 });
			if (qx - arr[qc + 1] >= 0) q.push({ qx - arr[qc + 1], qc + 1 });
		}
	}
	printf("%llu\n", result);	return 0;
}*/