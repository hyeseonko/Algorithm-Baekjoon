#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <queue>

using namespace std;

int map[100][100];
bool connected[100];
int N;
queue <int> q;

void BFS(int from, int by)
{
	connected[by] = true;
	q.push(by);
	while (!q.empty())
	{
		int qfirst = q.front();
		for (int i = 0; i < N; i++)
		{
			if (map[qfirst][i] == 1&& !connected[i]) {
				q.push(i);
				connected[i] = true;
			}
		}
		map[from][q.front()] = 1; // check if the grammar is correct
		q.pop();
	}
	memset(connected, false, sizeof(connected));
}
int main()
{
	/* INPUT */
	scanf("%d", &N); 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	/* BFS Starting Point */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1) {
				BFS(i, j);
			}
		}
	}

	/* OUTPUT */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

