/*
	TITLE: N-QUEEN
	BAEKJOON 9663
	CATEGORY: BACKTRACKING
	DATE: 2017-08-08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count;

bool check(int pPath[], int row)
{
	for (int i = 0; i < row; i++)
	{
		if (pPath[row] == pPath[i] || row - i == abs(pPath[row] - pPath[i]))
		{
			return true;
		}
	}
	return false;
}

void backtracking(int QueenNum, int row, int pPath[])
{
	for (int i = 0; i < QueenNum; i++)
	{
		pPath[row] = i;
		if (!check(pPath, row))
		{
			if (row == QueenNum - 1) count++;
			else {
				backtracking(QueenNum, row + 1, pPath);
			}
		}
	}
}

int main()
{
	int N; scanf("%d", &N);
	int pPath[15];
	backtracking(N, 0, pPath);
	printf("%d\n", count);	return 0;
}