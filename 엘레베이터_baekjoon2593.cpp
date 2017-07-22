/*
	TITLE: ELEVATOR
	BAEKJOON 2593
	KOI 2005 > MIDDLE SCHOOL > #04
	CATEGORY: BFS
	DATE: 2017-07-23
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool level_visited[100001]; // Check if level is visited
bool elev_visited[100001];
vector <int> level[100001]; // NÃþ¿¡ ¿¬°áµÈ ¿¤º£ÀÇ #
vector <int> elev[101]; // ¿¤º£ i°¡ ¼­´Â ÃþÀÇ #

queue <vector<int>> q;

int main()
{
	// INPUT
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int x, y; scanf("%d %d", &x, &y);
		for (int j = x; j <= N; j += y)
		{
			elev[i].push_back(j);
			level[j].push_back(i);
		}
	}
	int A, B; scanf("%d %d", &A, &B);
	for (int i = 0; i < level[A].size(); i++)
	{
		q.push({ level[A][i] });
		elev_visited[level[A][i]] = true;
	}
	level_visited[A] = true;

	while (!q.empty())
	{
		vector <int> tmp = q.front();
		q.pop();
		int num = tmp.back();
		for (int i = 0; i < elev[num].size(); i++)
		{
			int m = elev[num][i];
			if (m == B)
			{
				printf("%d\n", tmp.size());
				for (int j = 0; j < tmp.size(); j++) printf("%d\n", tmp[j]);
				return 0;
			}
			if (!level_visited[m])
			{
				int sz = level[m].size();
				for (int k = 0; k < sz; k++)
				{
					if (!elev_visited[level[m][k]])
					{
						vector <int> tmp1 = tmp;
						tmp1.push_back(level[m][k]);
						q.push(tmp1);
						elev_visited[level[m][k]] = true;
					}
				}
				level_visited[m] = true;
			}
		}
	}
	puts("-1");	return 0;
}