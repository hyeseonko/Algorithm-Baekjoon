/*
	TITLE: GPA CALCULATION
	BAEKJOON 10984
	University > KAIST > 2015 KAIST 5th ACM-ICPC Mock Competition #I
	CATEGORY: SIMULATION
	DATE: 2017-06-19
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int M; scanf("%d", &M);
		int sum1 = 0;
		float sum2 = 0;
		while (M--)
		{
			int credit;
			float score;
			scanf("%d %f", &credit, &score);
			sum1 += credit;
			sum2 += (credit*score);
		}
		sum2 /= sum1;
		printf("%d %.1f\n", sum1, sum2);
	}
	return 0;
}
/* HOW I SOLVED THIS */
/*
	1. 소수점 첫째자리로 반올림 출력하기
		%.1f 로 하면 된다

*/