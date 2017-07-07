/*
	TITLE: HOW MANY ISLANDS?
	BAEKJOON 4963
	ACM-ICPC > Regionals > Asia > Japan > Domestic Contest > 2009 Domestic Contest B¹ø
	CATEGORY: BFS
	DATE: 2017-07-07
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //memset
#include <queue>

using namespace std;

int map[51][51]; // initialized by zero
bool visited[51][51];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
queue <pair<int, int>> q;

int main()
{
	while (1)
	{
		int w, h; scanf("%d %d", &w, &h);
		// If the input is 0 0
		if (w == 0 && h == 0) break;
		// ELSE
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		int numberOfIslands = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && !visited[i][j])
				{
					q.push({ i,j });
					visited[i][j] = true;
					while (!q.empty())
					{
						int qx = q.front().first;
						int qy = q.front().second;
						q.pop();
						for (int k = 0; k < 8; k++)
						{
							int nx = qx + dx[k];
							int ny = qy + dy[k];
							if (nx >= 0 && nx <= h && ny >= 0 && ny <= w && map[nx][ny] == 1 && !visited[nx][ny])
							{
								q.push({ nx,ny });
								visited[nx][ny] = true;
							}
						}
					}
					numberOfIslands++;
				}
			}
		}
		printf("%d\n", numberOfIslands);
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}