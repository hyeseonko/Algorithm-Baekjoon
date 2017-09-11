/*
	TITLE: DUNGEON MASTER
	BAEKJOON 6593
	University of Ulm Local Contest 1997 D¹ø
	CATEGORY: BFS
	DATE: 2017-09-11
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef struct {
	int x;
	int y;
	int z;
	int cnt;
}b;
queue <b> q;
b target = {};
char map[31][31][31];
bool visited[31][31][31];
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

int main()
{
	while (1)
	{
		int L, R, C; scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				scanf("%s",map[i][j]);
				for (int k = 0; k < C; k++)
				{
					if (map[i][j][k] == 'S')
					{
						q.push({ i,j,k, 0 });
						visited[i][j][k] = true;
					}
					else if (map[i][j][k] == 'E')
					{
						target.x = i;
						target.y = j;
						target.z = k;
					}
				}
			}
		}
		while (!q.empty())
		{
			int qx = q.front().x;
			int qy = q.front().y;
			int qz = q.front().z;
			int qc = q.front().cnt;
			q.pop();
			if (qx == target.x&&qy == target.y&&qz == target.z)
			{
				printf("Escaped in %d minute(s).\n", qc);
				goto here;
			}
			for (int i = 0; i < 6; i++)
			{
				int nx = qx + dx[i];
				int ny = qy + dy[i];
				int nz = qz + dz[i];
				if (nx >= 0 && nx < L&&ny >= 0 && ny < R&&nz >= 0 && nz < C && !visited[nx][ny][nz] && (map[nx][ny][nz] == '.' || map[nx][ny][nz] == 'E'))
				{
					q.push({ nx,ny,nz,qc + 1 });
					visited[nx][ny][nz] = true;
				}
			}
		}
		puts("Trapped!");
	here:
		memset(visited, false, sizeof(visited));
		memset(map, NULL, sizeof(map));
		while (!q.empty()) q.pop();
	}
	return 0;
}