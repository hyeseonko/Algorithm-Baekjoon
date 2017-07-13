/*
	TITLE: ELECTRICAL OUTLETS
	BAEKJOON 2010
	CATEGORY: MATH
	DATE: 2017-07-13
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	int sum = 0;
	for(int i=0;i<N;i++)
	{
		int tmp; scanf("%d", &tmp);
		sum += tmp;
	}
	sum -= (N - 1);
	printf("%d\n", sum);
	return 0;
}
/* DIFFICULTY */
/*
	understanding the question was the most difficult.

*/
