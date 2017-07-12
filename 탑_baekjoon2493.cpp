/*
	TITLE: TOWER
	BAEKJOON 2493
	KOI 2009 > HIGH SCHOOOL #02
	CATEGORY: STACK
	DATE: 2017-07-12
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tower[500000];
int stack[500000][2];
int answer[500000];

int main()
{
	// INPUT 
	int N; scanf("%d\n", &N);
	for (int i = 0; i < N; i++) scanf("%d", &tower[i]);
	int top = 0;
	stack[0][0] = tower[0];
	stack[0][1] = 0;
	/* KEY POINT FUNCTION 'STACK' */
	for (int i = 1; i < N-1; i++)
	{
		if (stack[top][0] < tower[i])
		{
			stack[top][0] = tower[i];
			stack[top][1] = i;
		}
		else
		{
			top++;
			stack[top][0] = tower[i];
			stack[top][1] = i;
		}
	}
	for (int i = N-1;i>=1;i--)
	{
		if (i <= stack[top][1]) top--; // THINK ONLY AHEAD OF ME! SO TOP--
		for (int j = top; j >= 0; j--)
		{
			if (tower[i] < stack[j][0])
			{
				answer[i] = stack[j][1]+1;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", answer[i]);	return 0;
}
/* DIFFICULTY */
/*
	TLE O(n^2): SOLVED BY USING STACK
*/