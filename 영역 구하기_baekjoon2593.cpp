/*
	TITLE: CALCULATE THE AREA
	BAEKJOON 2593
	KOI 2006 HIGH SCHOOL #02
	CATEGORY: BFS, DFS
	DATE: 2017-06-02

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>    // vector
#include <algorithm> // sort

using namespace std;

queue <pair<int,int>> q;
vector <int> v;

int map[100][100];
bool visited[100][100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	int M, N, K; scanf("%d %d %d", &M, &N, &K);
	int count = 0;
	while (K--) {
		int x, y, z, w;
		scanf("%d %d %d %d", &x, &y, &z, &w);
		for (int i = M - w; i <= M - y - 1; i++) 	for (int j = x; j <= z - 1; j++) map[i][j] = 1;
		// If it's colored, then set arr[i][j] = 1
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j]==0&&!visited[i][j])
			{
				q.push({ i,j});
				visited[i][j] = true;
				int qcount = 0;
				while (!q.empty())
				{
					int fx = q.front().first;
					int fy = q.front().second;
					qcount++;
					q.pop();
					for (int a = 0; a < 4; a++)
					{
						int nx = fx + dx[a];
						int ny = fy + dy[a];
						if (nx >= 0 && nx <= M - 1 && ny >= 0 && ny <= N - 1 && map[nx][ny] == 0&&!visited[nx][ny])
						{
							q.push({ nx,ny});
							visited[nx][ny] = true;
						}
					}
				}
				count++;
				v.push_back(qcount);
			}
		}
	}
	printf("%d\n", count);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)	printf("%d ", v[i]);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	BFS using STL QUEUE
	I turend this problem into a new problem "Calculate the number of entries whose value is 0.

	Two Key points in this source code.
	1) Transformation
	for (int i = M - w; i <= M - y - 1; i++) 	for (int j = x; j <= z - 1; j++) map[i][j] = 1;

	2) BFS
	Similar method
*/