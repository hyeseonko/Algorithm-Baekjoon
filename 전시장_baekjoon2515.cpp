/*
	TITLE: EXHIBITION
	BAEKJOON 2515
	KOI MIDDLE 2012 #02
	CATEGORY: DP
	DATE: 2017-10-02
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
int dp[300000];

/* Lading amonst the index whose value is the biggest and at the same time, less than height-S+1 */
int getidx(int start, int end, int lessthan)
{
	if (v[0].first >= lessthan) return -1;
	else
	{
		while (start < end)
		{
			int mid = (start + end) / 2;
			if (v[mid].first < lessthan)
			{
				if (v[mid + 1].first >= lessthan) return mid;
				else start = mid + 1;
			}
			else end = mid;
		}
	}
}

int main()
{
	int N, S; scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		int H, C; scanf("%d %d", &H, &C);
		v.push_back({ H,C });
	}
	sort(v.begin(), v.end());
	dp[0] = v[0].second;
	for (int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1];
		int targetidx = getidx(0, i, v[i].first - S+1);
		if (targetidx == -1 && dp[i] < v[i].second) dp[i] = v[i].second;
		else if (targetidx != -1&&dp[i]<dp[targetidx]+v[i].second)
		{
			dp[i] = dp[targetidx] + v[i].second;
		}
		printf("%d %d\n", targetidx, dp[i]);
	}
	printf("%d\n", dp[N - 1]);
	return 0;
}