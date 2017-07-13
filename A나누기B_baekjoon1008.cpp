/*
	TITLE: A / B
	BAEKJOON 1008
	CATEGORY: MATH
	DATE: 2017-07-13
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double A, B;
	scanf("%lf %lf", &A, &B);
	printf("%.9f\n", A / B);
	return 0;
}
/* KEY POINT */
/*
	DOUBLE SCANF : %lf
	DECIMAL Nth POINT PRINTF: %.Nf

*/