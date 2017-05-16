#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
bool visited[125001]; //75,000 -> 100,000으로 가는거가 오래걸림

int main()
{
	int N, K;
	queue<pair<int,int>> q;
	scanf("%d %d", &N, &K);
	q.push(make_pair(N, 0));

	while (1)
	{
		int node = q.front().first;
		int times = q.front().second;
		visited[node] = true;
		if (node== K){
			printf("%d\n", times); break;
		}
		if (N >= K)
		{
			printf("%d\n", times+node-K); break;
		}
		if (node-1>=0&&!visited[node - 1]) 	q.push(make_pair(node - 1, times+1));
		if (node+1<=125000&&!visited[node + 1])   q.push(make_pair(node + 1, times+1));
		if (node*2<=125000&&!visited[node * 2])	q.push(make_pair(node * 2, times+1));
		q.pop();
	}
	return 0;
}