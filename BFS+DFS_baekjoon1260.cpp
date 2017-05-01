#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n;                // ������ ����
int map[1001][1001];
int visit[1001];
queue <int> q;        //BFS�� ���� ť


void DFS(int num)
{
	visit[num] = 1; // ���� num�� �湮�ߴٰ� ǥ��
	printf("%d ", num);
	for (int j = 1; j <= n; j++) {
		if (map[num][j] == 1 && !visit[j]) DFS(j);
	}
}

void BFS(int num) {
	visit[num] = 1; //���� num�� �湮�ߴٰ� ǥ��
	q.push(num);
	while(!q.empty())
	{ 
		for (int k = 1; k <= n; k++)
		{
			if (map[num][k] == 1 && !visit[k]) {
				visit[k] = 1;
				q.push(k);
			}
		}
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
}


int main() {
	int m, v; // n: Nodes m: Edges v: Starting node #
	int temp[2];
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &temp[0], &temp[1]);
		map[temp[0]][temp[1]] = map[temp[1]][temp[0]] = 1;
	}
	DFS(v); printf("\n");
	memset(visit, 0, sizeof(int)*(n + 1));
	BFS(v);
	return 0;
}