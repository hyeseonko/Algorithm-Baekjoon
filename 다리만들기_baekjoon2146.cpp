/*
	TITLE: CONSTRUCT THE SHORTEST BRIDGE
	BAEKJOON 2146
	CATEGORY: BFS
	DATE: 2017-08-22

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;
int arr[100][100];
bool visited[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<pair<int, int>>> v; // keypoint
vector<pair<int, int>> tempv; // keypoint
int complex_num;
int distance(int x1, int y1, int x2, int y2)
{
	int sum =-1;
	if (x1 > x2)
	{
		sum += (x1 - x2);
		if (y1 > y2)
		{
			sum += (y1 - y2);
		}
		else {
			sum += (y2 - y1);
		}
	}
	else {
		sum += (x2 - x1);
		if (y1 > y2)
		{
			sum += (y1 - y2);
		}
		else {
			sum += (y2 - y1);
		}
	}
	return sum;
}
void BFS(int m, int n)
{
	queue <pair<int, int>> q;
	q.push({ m,n });
	visited[m][n] = true;

	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();
		v[complex_num].push_back(make_pair(qx,qy)); // keypoint

		for (int k = 0; k < 4; k++)
		{
			int nx = qx + dx[k];
			int ny = qy + dy[k];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&arr[nx][ny] == 1 && !visited[nx][ny])
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && !visited[i][j])
			{
				v.push_back(tempv); // keypoint
				BFS(i, j);
				complex_num++;
			}
		}
	}
	int MIN = 197; //(0,0)~(199,199)
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int k = i+1; k < v.size(); k++)
			{
				for (int l = 0; l < v[k].size(); l++)
				{
					if (MIN > distance(v[i][j].first, v[i][j].second, v[k][l].first, v[k][l].second))
					{
						MIN = distance(v[i][j].first, v[i][j].second, v[k][l].first, v[k][l].second);
					}
				}
			}
		}
	}
	printf("%d\n", MIN);
	return 0;
}