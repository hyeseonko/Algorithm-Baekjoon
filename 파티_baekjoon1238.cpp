/*
	TITLE: SILVER COW PARTY
	BAEKJOON 1238
	USACO February 2007 Contest > Silver #03
	CATEGORY: DIJKSTRA ALGORITHM
	DATE: 2017-09-06
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
int graph1[1001][1001];
int graph2[1001][1001];
bool visited[1001];
int cost[1001];
int result[1001];

int GetIndex(bool *visited, int *cost)
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

void dijkstra(int Graph[][1001], bool *visited, int *cost, int start)
{
	for (int i = 1; i <= N; i++) //initialisation
	{
		visited[i] = false;
		cost[i] = INT_MAX;
	}
	cost[start] = 0;
	for (int i = 1; i <= N; i++)
	{
		int next = GetIndex(visited, cost);
		for (int j = 1; j <= N; j++)
		{
			if (Graph[next][j] && !visited[j] && (cost[j]==INT_MAX||cost[j] > cost[next] + Graph[next][j]))
			{
				cost[j] = cost[next] + Graph[next][j];
			}
		}
		visited[next] = true;
	}
}

int main()
{
	int M, X; scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++)
	{
		int from, to, val; scanf("%d %d %d", &from, &to, &val);
		graph1[from][to] = val;
		graph2[to][from] = val;
	}
	dijkstra(graph1, visited, cost, X);
	for (int i = 1; i <= N; i++)	result[i] += cost[i]; // From X to i
	dijkstra(graph2, visited, cost, X);
	for (int i = 1; i <= N; i++)	result[i] += cost[i]; // From X to i

	sort(result + 1, result + N + 1);
	printf("%d\n", result[N]);

	return 0;
}
/* METHOD */
/*
	1ST TRY: (1,X)+(X,1).....(N,X)+(X,N) 중 MAX 출력 >> 시간초과 (다익스트라 2N번 실행)
	2ND TRY: (X) + (x^-1) (다익스트라 2번실행) >> SUCCESS

*/