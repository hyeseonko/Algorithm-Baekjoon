/*
	Title: Glacier
	Baekjoon 2573
	KOI 2006 Elementary #2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[300][300];
bool visited[300][300];
queue <pair<int, int>> q;
int year;

typedef struct {
	int x;
	int y;
	int data;
}Glac;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int NumberOfGlaciers(); // Number of Glaciers
bool MeltedAll();       // check if the glaciers have already melted
void MeltingNow();

int main()
{
	/* INPUT */
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}/*
	MeltingNow();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", NumberOfGlaciers());
	MeltingNow();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", NumberOfGlaciers());*/
	while (1)
	{
		if (MeltedAll())
		{
			printf("0\n"); break;
		}
	
		if (NumberOfGlaciers() >= 2)
		{
			printf("%d\n", year);
			break;
		}
		MeltingNow(); year++;
	}
	return 0;
}

int NumberOfGlaciers() {
	int numbers = 0;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (map[i][j] > 0&&!visited[i][j]) 
			{
				q.push({ i,j });
				while (!q.empty())
				{
					int qfront_x = q.front().first;
					int qfront_y = q.front().second;
					for (int k = 0; k < 4; k++)
					{
						int next_x = qfront_x + dx[k];
						int next_y = qfront_y + dy[k];
						if (map[next_x][next_y] > 0 && !visited[next_x][next_y]) {
							q.push({ next_x, next_y });
							visited[next_x][next_y] = true;
						}
					}
					q.pop();
				}
				numbers++;
			}
			visited[i][j] = true;
		}
	}
	memset(visited, false, sizeof(visited));
	return numbers;
}

bool MeltedAll() {
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
			if (map[i][j] > 0) return false;
		}
	}
	return true;
}

void MeltingNow()
{
	//queue <pair<int,int>,int> tempq;
	queue <Glac> tq;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (map[i][j] > 0) {
				int temp = 0;
				for (int k = 0; k < 4; k++)
				{
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (map[ni][nj] == 0) temp++;
				}
				tq.push({ i,j,temp });
			}
		}
	}
	//printf("%d\n", tq.size());
	
	while (!tq.empty())
	{
		int frontq_x = tq.front().x;
		int frontq_y = tq.front().y;
		int minus_data = tq.front().data;
		if (map[frontq_x][frontq_y] - minus_data > 0)
			map[frontq_x][frontq_y] -=minus_data;
		else map[frontq_x][frontq_y] = 0;
		//map[frontq_x][frontq_y] - minus_data > 0 ? map[frontq_x][frontq_y] - minus_data : 0;
		tq.pop();
	}
}
\