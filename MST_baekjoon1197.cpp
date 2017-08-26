#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

#define MAX_VERTEX 10001
bool visited[MAX_VERTEX];

typedef pair<int, int> ii;
vector <ii> v[MAX_VERTEX];

int main()
{
	int V,E; scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(ii(b, c));
		v[b].push_back(ii(a, c));
	}
	
	visited[1] = true;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 0; i < v[1].size(); i++)
	{
		int nv = v[1][i].first;
		int nv_val = v[1][i].second;
		pq.push(ii(nv_val, nv));
	}

	int result = 0;
	while (!pq.empty())
	{
		int from = pq.top().second;
		int from_val = pq.top().first;
		pq.pop();
		if (!visited[from])
		{
			result += from_val;
			for (int i = 0; i < v[from].size(); i++)
			{
				int to = v[from][i].first;
				int to_val = v[from][i].second;
				pq.push(ii(to_val, to));
			}
		}
		visited[from] = true;
	}
	printf("%d\n", result);	return 0;
}