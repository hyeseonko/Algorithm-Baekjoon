/*
	TITLE: RESTORE THE NETWORK
	BAEKJOON 2211
	CATEGORY: DIJKSTRA
	DATE: 2017-09-22

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int graph[1001][1001];
bool visited[1001];
int cost[1001];
int prev[1001];
int N;

int GetIdx(bool *visited, int *cost)
{
	int min = INT_MAX;
	int idx;
	for (int i = 1; i <= N; i++)
	{
		if (cost[i]!=INT_MAX&&!visited[i] && cost[i] < min)
		{
			min = cost[i];
			idx = i;
		}
	}
	return idx;
}

int main()
{
	int M; scanf("%d %d", &N, &M);
	while (M--)
	{
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		graph[A][B] = graph[B][A] = C;
	}

	for (int i = 1; i <= N; i++)	cost[i] = INT_MAX;
	cost[1] = 0;
	for (int k = 1; k <= N; k++)
	{
		int next = GetIdx(visited, cost);
		for (int j = 1; j <= N; j++)
		{
			if (graph[next][j] && !visited[j] && (cost[j] == INT_MAX || cost[j] > cost[next] + graph[next][j]))
			{
				cost[j] = cost[next] + graph[next][j];
				prev[j] = next;
			}
		}
		visited[next] = true;
	}

	printf("%d\n", N - 1);
	for (int i = 2; i <= N; i++) printf("%d %d\n", i, prev[i]);	
	return 0;
}