/*
	TITLE: LUNCH
	BAEKJOON 5543
	JOI 2012 PRETEST #01
	DATE: 2017-06-05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int MIN[2] = { 2000,2000 };
	for (int i = 0; i < 3; i++)
	{
		int burger;
		scanf("%d", &burger);
		if (burger < MIN[0]) MIN[0] = burger;
	}
	for (int i = 0; i < 2; i++)
	{
		int drinks;
		scanf("%d", &drinks);
		if (drinks<MIN[1]) MIN[1] = drinks;
	}
	printf("%d\n", MIN[0] + MIN[1] - 50);
	return 0;
}