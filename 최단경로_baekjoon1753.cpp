/*
	TITLE: SHORTEST PATH
	BAEKJOON 1753
	CATEGORY: DIJKSTRA
	DATE: 2017-09-22
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
vector <ii> v[20001];

int main()
{
	int V, E, start;	scanf("%d %d %d", &V, &E, &start);
	while (E--)
	{
		int from, to, val;		scanf("%d %d %d", &from, &to, &val);
		v[from].push_back({ to,val });
	}

	vector <int> cost(V+1, INT_MAX);
	cost[start] = 0;

	priority_queue <ii, vector<ii>, greater<ii>> pq;

	pq.push({ 0, start });
	while (!pq.empty())
	{
		int pay1 = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (cost[from] < pay1) continue;

		for (int i = 0; i < v[from].size(); i++)
		{
			int to = v[from][i].first;
			int pay2 = v[from][i].second;
			if (cost[to] > pay2+cost[from])
			{
				cost[to] = pay2+cost[from];
				pq.push({ pay2, to });
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == INT_MAX) puts("INF");
		else printf("%d\n", cost[i]);
	}
	return 0;
}