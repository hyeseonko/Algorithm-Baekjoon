/*
	TITLE: JUMP JUMP
	BAEKJOON 11060
	CATEGORY: BFS
	DATE: 2017-09-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int arr[1000];
bool visited[1000];
queue <pair<int, int>> q;

int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	q.push({ 0,0 });
	visited[0] = true;
	while (!q.empty())
	{
		int qx = q.front().first;
		int qc = q.front().second;
		q.pop();
		if (qx == N - 1) {
			printf("%d\n", qc);
			return 0;
		}
		for (int i = 1; i <= arr[qx]; i++)
		{
			if (!visited[qx + i])
			{
				q.push({ qx + i, qc + 1 });
				visited[qx + i] = true;
			}
		}
	}
	puts("-1");	return 0;
}