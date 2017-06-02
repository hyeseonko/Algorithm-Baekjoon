/*
	TITLE: SAFE AREA
	BAEKJOON 2468
	KOI 2010 ELEMENTARY #02
	CATEGORY: BFS
	DATE: 2017-06-02
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //memset
#include <queue>
#include <vector>    // vector
#include <algorithm> // sort

using namespace std;

int N;
int map[100][100];
bool visited[100][100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pair<int, int>> q;
vector <int> v;

int Safety(int under) // below the integer will be sunk under water
{
	int areas = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > under&&!visited[i][j])
			{
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty())
				{
					int qx = q.front().first;
					int qy = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = qx + dx[k];
						int ny = qy + dy[k];
						if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1 && map[nx][ny] > under && !visited[nx][ny])
						{
							q.push({ nx,ny });
							visited[nx][ny] = true;
						}
					}
				}
				areas++;
			}
		}
	}
	return areas;
}

int main()
{
	scanf("%d", &N);
	int min = 100;
	int max = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (min > map[i][j]) min = map[i][j];      // To figure out the min value of all
			else if (max < map[i][j]) max = map[i][j]; // To figure out the max value of all
		}
	}
	v.push_back(1); // Because the minimum area will be 1.
	for (int i = min; i <= max; i++)	v.push_back(Safety(i)); // Using safety function above.
	sort(v.begin(), v.end());
	printf("%d\n", v.back());	return 0;
}

/* HOW I SOLVED THIS */
/*
	USING BFS AND SORTING ALGORITHM
*/