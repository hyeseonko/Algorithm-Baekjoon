/*
	TITLE: THE NUMBER OF CONNECTED COMPONENT
	BAEKJOON 11724
	CATEGORY: BFS, DFS
	DATE: 2017-06-20
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
queue <int> q;
int map[1001][1001];
bool visited[1001];

int main()
{
	int count = 0;
	int N, M; scanf("%d %d", &N, &M); // N: Vertex M: Edges
	while (M--)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		map[temp1][temp2] = map[temp2][temp1] = 1; // connected
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] == 1 && !visited[i])
				{
					q.push(j);
					visited[j] = true;
					while (!q.empty())
					{
						int qx = q.front();
						q.pop();
						for (int k = 1; k <= N; k++)
						{
							if (map[qx][k] == 1 && !visited[k])
							{
								q.push(k);
								visited[k] = true;
							}
						}
					}
				}
			}
			count++;
		}
	}
	printf("%d\n", count);	return 0;
}