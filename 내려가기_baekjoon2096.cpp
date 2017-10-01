/*
	TITLE: GOING DOWN
	BAEKJOON 2096
	CATEGORY: DP
	DATE: 2017-10-02	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp1[3];
int dp2[3];
int arr[100000][3];

int bigger(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int smaller(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	dp1[0] = dp2[0] = arr[0][0];
	dp1[1] = dp2[1] = arr[0][1];
	dp1[2] = dp2[2] = arr[0][2];

	for (int i = 1; i < N; i++)
	{
		int temp1[3] = { dp1[0], dp1[1], dp1[2] };
		int temp2[3] = { dp2[0], dp2[1], dp2[2] };
		dp1[0] = arr[i][0] + bigger(temp1[0], temp1[1]);
		dp1[1] = arr[i][1] + bigger(temp1[0], bigger(temp1[2], temp1[1]));
		dp1[2] = arr[i][2] + bigger(temp1[2], temp1[1]);

		dp2[0] = arr[i][0] + smaller(temp2[0], temp2[1]);
		dp2[1] = arr[i][1] + smaller(temp2[0], smaller(temp2[2], temp2[1]));
		dp2[2] = arr[i][2] + smaller(temp2[2], temp2[1]);
	}
	printf("%d %d\n", bigger(dp1[0], bigger(dp1[1], dp1[2])), smaller(dp2[0], smaller(dp2[1], dp2[2])));
	return 0;
}