/*
	TTILE: CANDY STORE
	BAEKJOON 4781
	2012 Southeast USA Regional Programming Contest Division 2 A¹ø
	CATEGORY: DP
	DATE: 2017-10-07
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define bigger(a,b) a>b?a:b
int coin[5000][2];
int dp[10001];
vector <pair<int, int>> v;
int main() {
	while (1) {
		int N; float M;	scanf("%d %f", &N, &M);
		int dest = (int)(M * 100 + 0.5);
		if (N == 0 && M == 0.00) break;
		for (int i = 0; i < N; i++)
		{
			int c; float f; scanf("%d %f", &c, &f);
			int ff = (int)(f * 100 + 0.5);
			v.push_back({ ff,c });
		}
		sort(v.begin(), v.end());
		for (int i = v[0].first; i <= dest; i++)	dp[i] = (i / v[0].first)*(v[0].second);
		for (int i = 1; i < N; i++)
		{
			for (int j = v[i].first; j <= dest; j++)
			{
				int temp = v[i].second + dp[j - v[i].first];
				dp[j] = bigger(dp[j], temp);
			}
		}
		for (int j = v[0].first; j <= dest; j += 100) printf("%d ", dp[j]); printf("\n");
		printf("%d\n", dp[dest]);
		v.clear();	memset(dp, 0, sizeof(dp));
	}
	return 0;
}