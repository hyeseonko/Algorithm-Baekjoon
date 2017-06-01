/*
	TITLE: CHANGE
	BAEKJOON 5585
	JOI 2008 #01
	CATEGORY: GREEDY ALGORITHM, SIMULATION
	DATE: 2017-06-01
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	int count = 0;
	N = 1000 - N;
	if (N >= 500){
		count += 1;
		N -= 500;
	}
	if (N >= 100){
		count += (N / 100);
		N -= 100 * (N / 100);
	}
	if (N >= 50){
		count += (N / 50);
		N -= 50 * (N / 50);
	}
	if (N >= 10){
		count += (N / 10);
		N -= 10 * (N / 10);
	}
	if (N >= 5){
		count += (N / 5);
		N -= 5 * (N / 5);
	}
	if (N >= 1)	count += N;

	printf("%d\n", count);	return 0;
}
/* HOW I SOLVED THIS */
/*
	TO GET A SMALLEST NUMBER OF COINS,
	THEN FIRST STARTING WITH THE BIGGEST INTEGER AND
	THEN THE SECOND BIGGEST.....AND THE LAST ONE.
	So, with repetition unitl the end, 
	then we get the solution 
*/