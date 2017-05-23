/*
	TITLE: CABBAGE
	BAEKJOON 1012
	CATEGORY: BFS, DFS
	DATE: 2017-05-22

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //memset
#include <queue>

using namespace std;

int map[51][51];
bool visited[51][51];
queue <pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int count = 0;
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		while (K--)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			map[temp2][temp1] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && !visited[i][j])
				{
					q.push({ i,j });
					visited[i][j] = true;
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx>=0 && nx<=N-1 && ny>=0 && ny<=M-1 && map[nx][ny] == 1 && !visited[nx][ny])
							{
								q.push({ nx,ny });
								visited[nx][ny] = true;
							}
							//visited[nx][ny] = true;
						}
					}
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}