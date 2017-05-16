/*
	TITLE: PERMUTATION CYCLE
	BAEKJOON 10451
	DATE: 2017-05-16
	FROM: ASIA REGIONAL-DAEJEON 2014 #F

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[1001];
int main()
{
	int T;
	scanf("%d", &T);  // TestCase
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int count = 0;
		for (int i = 1; i <= N; i++) scanf("%d", &arr[i]); // input
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] == i) { arr[i] = 0; count++; continue; }
			int from = i;
			int by = arr[i];
			while (by!=0)
			{
				if (from == arr[by]) { arr[by] = 0; count++; break; }
				else by = arr[by];
			}
		}
		printf("%d\n", count);
	}
	return 0;
}