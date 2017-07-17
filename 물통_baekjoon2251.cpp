/*
	TITLE: WATER BOTTLE
	BAEKJOON 2251
	CATEGORY: BFS
	DATE: 2017-07-17
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm> // sort

using namespace std;

typedef struct {
	int A;
	int B;
	int C;
}water;

queue <water> q;
vector <int> v;
int MAX[3]; 
int front[3];
int tmp[3];

bool visited[201][201][201];

int main()
{
	scanf("%d %d %d", &MAX[0], &MAX[1], &MAX[2]);
	q.push({ 0,0,MAX[2] });
	visited[0][0][MAX[2]] = true;

	while (!q.empty())
	{
		front[0] = q.front().A; // front A
		front[1] = q.front().B; // front A
		front[2] = q.front().C; // front 
		q.pop();

		if (front[0] == 0) v.push_back(front[2]);

		for (int i = 0; i < 3; i++)
		{
			if(front[i]!=0)
			{ 
				for (int j = 0; j < 3; j++)
				{
					tmp[0] = front[0];
					tmp[1] = front[1];
					tmp[2] = front[2];
					
					if (j != i)
					{
						if (front[i] + front[j] > MAX[j])
						{
							tmp[j] = MAX[j];
							tmp[i] -= (MAX[j] - front[j]);
						}
						else
						{
							tmp[j] += tmp[i];
							tmp[i] = 0;
						}

						if (!visited[tmp[0]][tmp[1]][tmp[2]])
						{
							q.push({ tmp[0], tmp[1], tmp[2] });
							visited[tmp[0]][tmp[1]][tmp[2]] = true;
						}
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	return 0;
}