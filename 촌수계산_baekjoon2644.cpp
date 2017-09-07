/*
	TITLE: CACULATE THE RELATIVES NUMBER
	BAEKJOON 2644
	KOI 1999 > MIDDLE SCHOOL #01
	CATEGORY: BFS
	DATE: 2017-09-07
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector <int> childrenof[101];
vector <int> parentsof[101];
queue <pair<int, int>> q;
bool visited[101];
int main()
{
	int N; scanf("%d", &N);
	int start, end; scanf("%d %d", &start, &end);
	int M; scanf("%d", &M);

	while (M--)
	{
		int up, down; scanf("%d %d", &up, &down);
		childrenof[up].push_back(down);
		parentsof[down].push_back(up);
	}

	q.push({ start, 0 });
	visited[start] = true;
	while (!q.empty())
	{
		int qnum = q.front().first;
		int qcnt = q.front().second;
		q.pop();
		if (qnum == end)
		{
			printf("%d\n", qcnt);
			return 0;
		}
		for (int i = 0; i < childrenof[qnum].size(); i++)
		{
			int temp = childrenof[qnum][i];
			if (!visited[temp])
			{
				q.push({ temp,qcnt + 1 });
				visited[temp] = true;
			}
		}
		for (int i = 0; i < parentsof[qnum].size(); i++)
		{
			int temp = parentsof[qnum][i];
			if (!visited[temp]) 
			{
				q.push({ temp,qcnt + 1 });
				visited[temp] = true;
			}
		}

	}
	puts("-1");	return 0;
}