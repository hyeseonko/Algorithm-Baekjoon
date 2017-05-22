/*
	TITLE: VIRUS
	BAEKJOON 2606
	KOI ELEMENTARY 2004 #03
	CATEGORY: FLOYD-WARSHALL ALGORITHM
	DATE: 2017-05-22

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int map[101][101];
bool visited[101];
int N;
void virus(int x)
{
	for (int i = 2; i <= N; i++)
	{
		if (map[x][i] == 1&&!visited[i]) {
			visited[i] = true;
			virus(i);
		}
	}
}

int main()
{
	scanf("%d", &N); // Computers
	int E; scanf("%d", &E); // Connection Numbers
	while (E--)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		map[temp1][temp2] = map[temp2][temp1] = 1;
	}
	virus(1);
	int count = 0;
	for (int i = 2; i <= N; i++)
		if (visited[i] == true) count++;
	printf("%d\n", count);
	return 0;
}