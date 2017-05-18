/*
	TITLE: SOVLE PRIME NUMBER
	BAEKJOON 1929
	DATE: 2017-05-18
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[1000001];
int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 2; i <= N; i++)for (int j = i + i; j <= N; j += i)	arr[j] = 0;
	for (int i = M; i <= N; i++)  if (arr[i] != 0) printf("%d\n", arr[i]);
	return 0;
}