/*
	TITLE: MOVE BY BREAKING WALLS
	BAEKJOON 2206
	CATEGORY: BFS
	DATE: 2017-08-09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
	int x;
	int y;
	int count;
	int allow;
}Q;
queue <Q> q;

bool visited[1000][1000][2]; // [2] 추가 안하니까 예외 상황 발생함.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[1000][1000];
int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	if (N == 1 && M == 1) {
		puts("1"); return 0;
	}
	q.push({ 0,0,1,0 });
	visited[0][0][0] = true;
	while (!q.empty())
	{
		int qx = q.front().x;
		int qy = q.front().y;
		int qcount = q.front().count;
		int qallow = q.front().allow;
		if (qx == N - 1 && qy == M - 1)
		{
			printf("%d\n", qcount);
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < M && !visited[nx][ny][qallow])
			{
				if (arr[nx][ny] == 0)
				{
					q.push({ nx,ny,qcount + 1,qallow });
					visited[nx][ny][qallow] = true;
				}
				else if (arr[nx][ny] == 1 && qallow == 0)
				{
					q.push({ nx,ny,qcount + 1,qallow + 1 });
					visited[nx][ny][1] = true;
				}
			}
		}
	}
	puts("-1");	return 0;
}