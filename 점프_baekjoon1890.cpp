/* 
	TITLE: JUMP THE BOARD!
	BAEKJOON 1890
	BALTIC OLYMPIAD IN INFORMATICS 2006 #06
	DATE: 2017-05-18

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[100][100];
unsigned long long ans[100][100]; // pathmap=ans

int main()
{
	/* INPUT */
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	scanf("%d", &map[i][j]);
	
	/* FUNCTION */
	ans[0][0] = 1;
	map[N - 1][N - 1] = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int jump = map[i][j];
			if (jump + i <= N - 1 && map[jump + i][j] != 0 && ans[i][j] == 1) ans[i + jump][j] += ans[i][j];
			if (jump + j <= N - 1 && map[i][j+jump] != 0 && ans[i][j] == 1) ans[i][j + jump] += ans[i][j];
		}
	}

	/* OUTPUT */
	printf("%llu\n", ans[N-1][N-1]);
	return 0;
}