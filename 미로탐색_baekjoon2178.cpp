#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
	int num;
}maze;

queue <maze> q;
int ans;
int map[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	/* INPUT */
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	/* BFS */
	q.push({ 0,0,1 }); // starting point
	while (!q.empty())
	{
		int xx = q.front().x;
		int yy = q.front().y;
		int numnum = q.front().num;
		if (xx == N - 1 && yy == M - 1) {ans = numnum; break; }
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (map[nx][ny] == 1 && nx <= N - 1 && ny <= M - 1) q.push({ nx,ny,numnum+1 });
		}
	}
	/* OUTPUT */
	printf("%d\n", ans);
	return 0;
}