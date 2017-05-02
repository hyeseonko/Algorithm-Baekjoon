#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

typedef struct {
	int x;
	int y;
	int day;
}tomato;

queue<tomato> q;
int box[1000][1000];
int visit[1000][1000];
int x_ctrl[4] = { 1,-1,0,0 };
int y_ctrl[4] = { 0,0,1,-1 };
int m, n, d;

int main()
{
	/* INPUT */
	int temp = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
			visit[i][j] = -1;           // 아직 큐에 들어오지 않았다.
			if (box[i][j] == 1)
			{
				visit[i][j] = 0;        // 익은 토마토라서 visit=0으로 바뀌구 큐에 들어왔다.
				q.push({ i,j,1 });
			}
		}
	}
	/* 시작하기 전 0이 존재하지 않는다면 모두 익은 상태라고 가정: 0 출력 */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0) temp++;
		}
	}
	if (temp == 0) {
		printf("0\n");
		return 0;
	}
	else {
		while (!q.empty())
		{
			int a = q.front().x;
			int b = q.front().y;
			d = q.front().day;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int next_a = a + x_ctrl[k];
				int next_b = b + y_ctrl[k];
				if (box[next_a][next_b] == 0 && visit[next_a][next_b] == -1 && next_a >= 0 && next_a<n&&next_b >= 0 && next_b<m) // 썩은 토마토이면서, 아직 큐에 들어오지 않았다면
				{
					box[next_a][next_b] = 1;
					visit[next_a][next_b] = 0;       // 큐에 들어왔다.
					q.push({ next_a, next_b, d + 1 });
				}
			}
		}
		/* 해도 썩은토마토인 0이 존재하면 -1 출력해라 */
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (box[i][j] == 0) {
					printf("-1\n");
					return 0;
				}
			}
		}
		/* 정상적인 경우 */
		printf("%d\n", d - 1);
		return 0;
	}
}