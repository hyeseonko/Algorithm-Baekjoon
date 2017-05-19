/*
	TITLE: CHEBYSHEV'S THEOREM
	BAEKJOON 4948
	JAPAN DOMESTIC CONTEST 2011 #A
	DATE: 2017-05-19

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //memset
int arr[250000];
int main()
{
	while (1)
	{
		int n; 
		int count = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 2; i <= n*2; i++) arr[i] = i;
		for (int i = 2; i <= n; i++) for (int j = i + i; j <= n*2; j += i)	arr[j] = 0;
		for (int i = n + 1; i <= 2 * n; i++) if (arr[i] > 0) count++;
		printf("%d\n", count);
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}