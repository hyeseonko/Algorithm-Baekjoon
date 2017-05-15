/*
	TITLE: MAKE TO ONE
	BAEKJOON 1463
	DATE: 2017-05-15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int map[1000001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 2; i <=N; i++) {
		map[i] = map[i - 1] + 1;
		if (i % 2 == 0) map[i] = (map[i] > map[i / 2] + 1) ? map[i / 2] + 1 : map[i];
		if (i % 3 == 0) map[i] = (map[i] > map[i / 3] + 1) ? map[i / 3] + 1 : map[i];
	}
	printf("%d\n", map[N]);
	return 0;
}