#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>  
#include <queue>  
#include <algorithm>

using namespace std;

int N;           
int map[30][30];
bool visited[30][30];        // 1, 0 하니까 하두 헷갈려서 true, false bool로
vector<int> houses;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int complex_num = -1;
void BFS(int x, int y);

int main()
{
	/* 예제 입력 */
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	/* BFS 시작할 포인트 찾기 */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				complex_num++;
				houses.push_back(1);
				BFS(i, j);
			}
		}
	}
	printf("%d\n", complex_num + 1);
	sort(houses.begin(), houses.end());
	for (int i = 0; i < houses.size(); i++)
	{
		printf("%d\n", houses[i]);
	}
	return 0;
}

void BFS(int x, int y)
{
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x2 = x1 + dx[i];
			int y2 = y1 + dy[i];
			if (x2 >= 0 && y2 >= 0 && x2 < N && y2 < N)
			{
				if (map[x2][y2] == 1 && !visited[x2][y2])
				{
					visited[x2][y2] = true;
					q.push(make_pair(x2, y2));
					houses[complex_num]++;
				}
			}
		}
	}
}