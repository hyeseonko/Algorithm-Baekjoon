/* 
	TITLE: COLORED PAPER
	BAEKJOON 2563
	Olympiad > KOI 2007 > ELEMENTARY #02
	CATEGORY: SIMULATION
	DATE: 2017-07-13

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool visited[100][100];
int main()
{
	int N; scanf("%d", &N);
	int MAX1 = 0;
	int MAX2 = 0;
	while (N--)
	{
		int temp1, temp2; scanf("%d %d", &temp1, &temp2);
		if (temp2 > MAX1) MAX1 = temp2;
		if (temp1 > MAX2) MAX2 = temp1;
		for (int i = temp2 - 1; i < temp2 + 9; i++)		for (int j = temp1 - 1; j < temp1 + 9; j++)	visited[i][j] = true;
	}
	int ans = 0;
	for (int i = 0; i < MAX1+10; i++)	for (int j = 0; j < MAX2+10; j++)	if (visited[i][j]) ans++;
	printf("%d\n", ans);	return 0;
}