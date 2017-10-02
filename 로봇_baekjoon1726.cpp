/*
	TITLE: ROBOT
	BAEKJOON 1726
	KOI HIGH SCHOOL 2005 #03
	CATEGORY: BFS
	DATE: 2017-10-02
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
	int x;
	int y;
	int d;
	int c;
}robot;
queue <robot> q;
int arr[101][101];
bool visited[101][101][4];
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int main()
{
	int M, N; scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int sx, sy, sd, dx, dy, dd; scanf("%d %d %d %d %d %d", &sx, &sy, &sd, &dx, &dy, &dd);
	q.push({ sx,sy,sd,0 });
	visited[sx][sy][sd] = true;
	while (!q.empty())
	{
		int curx = q.front().x;
		int cury = q.front().y;
		int curd = q.front().d;
		int curc = q.front().c;
		if (curx == dx&&cury == dy&&curd == dd)
		{
			printf("%d\n", curc);
			return 0;
		}
		q.pop();

		// First: 방향바꾸기
		if ((curd - 1) / 2 == 0)
		{
			if (!visited[curx][cury][3])
			{
				q.push({ curx,cury,3,curc + 1 });
				visited[curx][cury][3] = true;
			}
			if (!visited[curx][cury][4])
			{
				q.push({ curx,cury,4,curc + 1 });
				visited[curx][cury][4] = true;
			}
		}
		else
		{
			if (!visited[curx][cury][1])
			{
				q.push({ curx,cury,1,curc + 1 });
				visited[curx][cury][1] = true;
			}
			if (!visited[curx][cury][2])
			{
				q.push({ curx,cury,2,curc + 1 });
				visited[curx][cury][2] = true;
			}
		}
		// Second: 움직이기(1,2,3칸)
		for (int i = 1; i <= 3; i++)
		{
			int nx = curx + xx[curd - 1] * i;
			int ny = cury + yy[curd - 1] * i;
			if (nx >= 1 && nx <= M&&ny >= 1 && ny <= N && !visited[nx][ny][curd])
			{
				if (arr[nx][ny] == 1) break;
				q.push({ nx,ny,curd, curc + 1 });
				visited[nx][ny][curd] = true;
			}
		}
	}
	return 0;
}