/*
	TITLE: STONE BRIDGE
	BAEKJOON 12761
	2016 전북대 프로그래밍 경진대회 #G
	CATEGORY: BFS
	DATE: 2017-09-05

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define MAX_DOL 100001
using namespace std;
queue <pair<int, int>> q;
bool visited[MAX_DOL];

int main()
{
	int A, B, N, M; scanf("%d %d %d %d", &A, &B, &N, &M);
	if (N == M) { puts("0"); return 0; }
	
	q.push({ N,0 });
	visited[N] = true;
	while (!q.empty())
	{
		int curpos = q.front().first;
		int curcnt = q.front().second;
		q.pop();

		int jump[10] = { 1,-1,A,-A,B,-B, curpos*(A-1), curpos*(B-1), curpos*(-A-1), curpos*(-B-1)};
		for (int i = 0; i < 10; i++)
		{
			int nextpos = curpos + jump[i];

			if (nextpos >= 0 && nextpos <= MAX_DOL-1 &&!visited[nextpos])
			{
				if (nextpos == M)
				{
					printf("%d\n", curcnt + 1);
					return 0;
				}
				q.push({ nextpos,curcnt + 1 });
				visited[nextpos] = true;
			}
		}
	}
	return 0;
}