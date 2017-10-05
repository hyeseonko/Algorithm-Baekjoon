/*
	TITLE: MOVE THE TREE
	BAEKJOON 1938
	KOI 1998 > HIGH SCHOOL #02
	CATEGORY: BFS
	DATE: 2017-10-05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef struct
{
	int x;
	int y;
	int d;
	int c;
}qq;

queue <qq> q;
bool visited[51][51][2];
int dx[4] = {-1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[51][51];
int tree[3][2];
int dest[3][2];

int main()
{
	/* INPUT */
	int N; scanf("%d", &N);
	int idx = 0;
	int id = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		getchar();
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'B')
			{
				tree[idx][0] = i;
				tree[idx][1] = j;
				idx++;
			}
			else if (arr[i][j] == 'E')
			{
				dest[id][0] = i;
				dest[id][1] = j;
				id++;
			}
		}
	}

	if (dest[0][0] == dest[1][0]) dest[0][0] = 0;
	else dest[0][0] = 1;

	if (tree[0][0] == tree[1][0])
	{
		q.push({ tree[1][0], tree[1][1], 0,0 });
		visited[tree[1][0]][tree[1][1]][0] = true;
	}
	else
	{
		q.push({ tree[1][0], tree[1][1], 1,0 });
		visited[tree[1][0]][tree[1][1]][1] = true;
	}
	/* BFS */
	while (!q.empty())
	{
		int qx = q.front().x;
		int qy = q.front().y;
		int qd = q.front().d;
		int qc = q.front().c;
		q.pop();
		if (qx == dest[1][0] && qy == dest[1][1] && qd == dest[0][0])
		{
			printf("%d\n", qc);
			return 0;
		}
		else if (qd == 0)
		{
			// up
			if(qx-1>=0&&!visited[qx-1][qy][0]&&arr[qx-1][qy-1]!='1'&&arr[qx - 1][qy] != '1'&&arr[qx - 1][qy + 1] != '1')
			{
				q.push({ qx - 1,qy,0,qc + 1 });
				visited[qx - 1][qy][0] = true;
			}
			// down
			if (qx + 1 < N && !visited[qx +1][qy][0] && arr[qx+ 1][qy - 1] != '1'&&arr[qx+ 1][qy] != '1'&&arr[qx + 1][qy + 1] != '1')
			{
				q.push({ qx +1,qy,0,qc + 1 });
				visited[qx + 1][qy][0] = true;
			}
			// right
			if (qy + 2 < N && !visited[qx][qy+1][0] && arr[qx][qy + 2] != '1')
			{
				q.push({ qx,qy+1,0,qc + 1 });
				visited[qx][qy][0] = true;
			}
			// left
			if (qy - 2 >=0 && !visited[qx][qy - 1][0] && arr[qx][qy - 2] != '1')
			{
				q.push({ qx,qy - 1,0,qc + 1 });
				visited[qx][qy-1][0] = true;
			}
			// turn
			if (qx>=1&&qx<=N-2&&qy>=1&&qy<=N-2&&!visited[qx][qy][1]&& arr[qx - 1][qy - 1] != '1' && arr[qx - 1][qy] != '1' && arr[qx - 1][qy + 1] != '1' && arr[qx + 1][qy - 1] != '1' && arr[qx + 1][qy] != '1' && arr[qx + 1][qy + 1] != '1')
			{
				q.push({ qx,qy,1,qc + 1 });
				visited[qx][qy][1] = true;
			}
		}
		else 
		{
			// right
			if (qy+1<N && !visited[qx][qy+1][1] && arr[qx][qy + 1] != '1'&&arr[qx - 1][qy+1] != '1'&&arr[qx + 1][qy + 1] != '1')
			{
				q.push({ qx,qy + 1,1,qc + 1 });
				visited[qx][qy + 1][1] = true;
			}
			// left
			if (qy- 1 >=0 && !visited[qx][qy-1][1] && arr[qx - 1][qy - 1] != '1'&&arr[qx][qy-1] != '1'&&arr[qx + 1][qy - 1] != '1')
			{
				q.push({ qx,qy-1,1,qc + 1 });
				visited[qx][qy-1][1] = true;
			}
			// up
			if (qx-2>=0 && !visited[qx-1][qy][1] && arr[qx-2][qy] != '1')
			{
				q.push({ qx-1,qy,1,qc + 1 });
				visited[qx-1][qy][1] = true;
			}
			// down
			if (qx+2<N && !visited[qx+1][qy][1] && arr[qx+2][qy] != '1')
			{
				q.push({ qx+1,qy,1,qc + 1 });
				visited[qx+1][qy][1] = true;
			}
			// turn
			if (qy>=1&&qy<=N-2&&qx>=1&&qx<=N-2&&!visited[qx][qy][0]&&arr[qx - 1][qy - 1] != '1' && arr[qx][qy - 1] != '1' && arr[qx + 1][qy - 1] != '1' && arr[qx - 1][qy + 1] != '1' && arr[qx][qy + 1] != '1' && arr[qx + 1][qy + 1] != '1')
			{
				q.push({ qx,qy,0,qc + 1 });
				visited[qx][qy][0] = true;
				
			}
		}
	}
	puts("0");	return 0;
}