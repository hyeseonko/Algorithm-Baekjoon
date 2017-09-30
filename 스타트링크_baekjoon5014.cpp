/*
	TITLE: Elevator Trouble
	BAEKJOON 5014
	Nordic Collegiate Programming Contest > NCPC 2011 D
	CATEGORY: BFS
	DATE: 2017-09-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
queue <pair<int,int>> q;
bool visited[1000001];
int main()
{
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	q.push({ S,0 });
	visited[S] = true;
	while (!q.empty())
	{
		int qx = q.front().first;
		int qc = q.front().second;
		q.pop();
		if (qx == G) {
			printf("%d\n", qc);
			return 0;
		}
		int temp1 = qx + U;
		int temp2 = qx - D;
		if (temp1 <= F&&!visited[temp1])
		{
			q.push({ temp1 , qc + 1 }); visited[temp1] = true;
		}
		if ( temp2 >= 1 && !visited[temp2])
		{
			q.push({ temp2, qc + 1 }); visited[temp2] = true;
		}
	}
	puts("use the stairs");	return 0;
}