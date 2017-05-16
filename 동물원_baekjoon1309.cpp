/*
	TITLE: ZOO
	BAEKJOON1309
	DATE: 2017-05-16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NOTHING 0
#define LEFT 1
#define RIGHT 2

int map[100001][3];
int main()
{
	int N;
	scanf("%d", &N);
	map[1][NOTHING] = map[1][LEFT] =map[1][RIGHT]= 1;
	for (int i = 2; i <= N; i++)
	{
		map[i][NOTHING] = (map[i - 1][NOTHING] + map[i - 1][LEFT] + map[i - 1][RIGHT])%9901;
		map[i][LEFT]= (map[i - 1][NOTHING] + map[i - 1][RIGHT]) % 9901;
		map[i][RIGHT]= (map[i - 1][NOTHING] + map[i - 1][LEFT]) % 9901;
	}
	printf("%d\n", (map[N][NOTHING] + map[N][LEFT] + map[N][RIGHT]) % 9901);
	return 0;
}