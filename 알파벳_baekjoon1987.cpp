/*
	TITLE: ALPHABET
	BAEKJOON 1987
	Croatian Highschool Competitions in Informatics > 2002 > Regional Competition - Juniors 3
	CATEGORY: BACKTRACKING
	DATE: 2017-08-08
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char str[21][21];
int map[20][20];
int MAX, R, C;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool check(int pPath[], int step)
{
	for (int i = 0; i < step; i++)
	{
		if (pPath[i] == pPath[step]) return true;
	}
	return false;
}

void backtracking(int curx, int cury, int step, int pPath[])
{
	if (MAX < step) MAX = step;
	for (int i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];
		if (nx >= 0 && nx < R&&ny >= 0 && ny < C)
		{
			pPath[step] = map[nx][ny];
			if (!check(pPath, step))
			{
				backtracking(nx, ny, step + 1, pPath);
			}
		}
	}
}
int main()
{
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%c", &str[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j] = str[i][j] - 65;
		}
	}
	int pPath[30] = { map[0][0], };
	backtracking(0, 0, 1, pPath);
	printf("%d\n", MAX);	return 0;
}