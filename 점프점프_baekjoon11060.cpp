/*
	TITLE: JUMP JUMP
	BAEKJOON 11060
	CATEGORY: DP
	DATE: 2017-06-19
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm> //sort
using namespace std;

int dp[1000];
vector <int> v;

int main()
{
	int arr[1000];
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	if (arr[0] == 0)
	{
		if (N == 1) puts("0");
		else puts("-1");
	}
	else
	{
		dp[0] = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = i - 1; j >= 0&& j >= i - 100; j--)
			{
				if (arr[j] >= (i - j) && dp[j] >= 0)
				{
					v.push_back(dp[j] + 1);
				}
			}
			if (v.empty()) dp[i] = -1;
			else
			{
				sort(v.begin(), v.end());
				dp[i] = v.front();
			}
			v.clear();
		}
		printf("%d\n", dp[N - 1]);
	}
	return 0;
}