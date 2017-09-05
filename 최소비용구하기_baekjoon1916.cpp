#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <limits.h>

long long graph[1001][1001];
bool visited[1001];
long long cost[1001];
int prev[1001];
int N;

int GetSmallestIndex(long long *cost, bool *visited)
{
	int smallest_index;
	long long min = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && cost[i]!= INT_MAX &&min > cost[i])
		{
			min = cost[i];
			smallest_index = i;
		}
	}
	return smallest_index;
}

void dijkstra(int start, long long *cost, bool *visited)
{
	cost[start] = 0;
	for (int j = 0; j < N; j++)
	{
		int nextIndex = GetSmallestIndex(cost, visited);
		for (int i = 1; i <= N; i++)
		{
			if (graph[nextIndex][i]>=0 && !visited[i] && cost[nextIndex]!= INT_MAX &&(cost[i] > cost[nextIndex] + graph[nextIndex][i]))
			{
				cost[i] = cost[nextIndex] + graph[nextIndex][i];
				prev[i] = nextIndex;
				//printf("cost[%d]=%lld\n", i, cost[i]);
			}
		}
		visited[nextIndex] = true;
	}
}


int main()
{
	int M; scanf("%d", &N); scanf("%d", &M);
	for (int i = 1; i <= N; i++)
	{
		cost[i] = INT_MAX;
		visited[i] = false;
		prev[i] = 0;
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = -1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int from, to, value; scanf("%d %d %d", &from, &to, &value);
		if (graph[from][to] != -1 && value > graph[from][to]) continue;
		graph[from][to] = value;
	}

	int start, end;
	scanf("%d %d", &start, &end);
	dijkstra(start, cost, visited);
	printf("%lld\n", cost[end]);	return 0;
}