/*
	TITLE: STAND IN A LINE
	BAEKJOON 1138
	CATEGORY: MATH
	DATE: 2017-06-19
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[10];
int ans[11];
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = N - 1; i >= 0; i--)
	{
		int temp = arr[i]; // ith index of insertion
		if (ans[temp] == 0) ans[temp] = i + 1; 
		else
		{
			int cur = temp;
			while (ans[cur] != 0)	cur++;
			for (int j = cur; j > temp; j--)		ans[j] = ans[j - 1];
			ans[temp] = i + 1;
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", ans[i]);
	printf("\n"); 	return 0;
}