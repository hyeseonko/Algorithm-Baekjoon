/*
	TITLE: OBSTACLE COURSE
	BAEKJOON 4485
	2008 Pacific Northwest Region Programming Contest D
	CATEGORY: DIJKSTRA
	DATE: 2017-09-15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
queue <pair<int, int>> q;
int map[125][125];
int cost[125][125];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;

int main()
{
	while (1)
	{
		int N; scanf("%d", &N);
		if (N == 0) break;
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				cost[i][j] = 140625;
			}
		}
		q.push({ 0,0 });
		cost[0][0] = map[0][0];
		while (!q.empty())
		{
			int qx = q.front().first;
			int qy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = qx + dx[i];
				int ny = qy + dy[i];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N && cost[nx][ny] > cost[qx][qy] + map[nx][ny])
				{
					cost[nx][ny] = cost[qx][qy] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
		printf("Problem %d: %d\n", ++cnt, cost[N - 1][N - 1]);
	}
	return 0;
}