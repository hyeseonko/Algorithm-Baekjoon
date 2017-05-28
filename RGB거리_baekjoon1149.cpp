/*
	TITLE: RGB STREET
	BAEKJOON 1149
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-28
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int map[1000][3];
int R[1000], B[1000], G[1000];
int smaller(int a, int b)
{
	if (a > b) return b;
	else return a;
}
int main()
{
	int N; scanf("%d", &N); // input N
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}
	R[0] = map[0][0];
	G[0] = map[0][1];
	B[0] = map[0][2];
	for (int x = 1; x < N; x++)
	{
		R[x] = map[x][0] + smaller(G[x - 1], B[x - 1]);
		G[x] = map[x][1] + smaller(R[x - 1], B[x - 1]);
		B[x] = map[x][2] + smaller(G[x - 1], R[x - 1]);
	}
	int result = smaller(smaller(R[N-1], G[N-1]), B[N-1]);
	printf("%d\n", result);
	return 0;
}