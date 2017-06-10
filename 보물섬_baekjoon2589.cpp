/*
	TITLE: TREASURE ISALND
	BAEKJOON 2589
	Olympiad > KOI 2005 > ELEMENTARY #03
	CATEGORY: BFS
	DATE: 2017-06-11
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h> // memset
#include <queue>    // queue

using namespace std;

typedef struct{
	int x;
	int y;
	int d;
}mapinfo;

queue <mapinfo> q;
char map[50][50];
bool visited[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int MAX = 0;

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			memset(visited, false, sizeof(visited));
			if (map[i][j] == 'L')
			{
				q.push({ i,j,0});
				visited[i][j] = true;
				while (!q.empty())
				{
					int qx = q.front().x;
					int qy = q.front().y;
					int qd = q.front().d;
					if (qd >MAX) MAX = qd;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = qx + dx[k];
						int ny = qy + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 'L' && !visited[nx][ny])
						{
							q.push({ nx,ny,qd+1 });
							visited[nx][ny] = true;
						}
					}
				}//while
			}//if
		}//forj
	}//fori
	printf("%d\n", MAX);	return 0;
}