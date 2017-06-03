/*
	TITLE: THE NUMBER OF ZERO IN COMBINATIONS
	BAEKJOON 2004
	CATEGORY: MATH + COMBINATORICS
	DATE: 2017-06-04

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define smaller(a,b) (a>b?b:a)
int TWO(int x)
{
	int tcount = 0;
	for (unsigned int i = 2; i <= x; i *= 2)	tcount += x / i;
	return tcount;
}
int FIVE(int x)
{
	int fcount = 0;
	for (long long i = 5; i <= x; i *= 5)	fcount += x / i;
	return fcount;
}
int main()
{
	int M, N; scanf("%d %d", &N, &M);
	printf("%d\n", smaller(TWO(N) - TWO(M) - TWO(N - M), FIVE(N) - FIVE(M) - FIVE(N - M)));
	return 0;
}
/* HOW I SOLVED THIS */
/*
	Calculate the min(number of 2, number of 5) but to solve this, I approached in two ways below
	# first method : time limit over!!!
	# second method : succeeded!!! 

	# first method:
	using while-loop until the specfic integer is not divided into 2 or 5 anymore.
	I think that in this way, computer has to look up for every integer(between a and b) so it was time limit over!
	So, the second method is way faster!!

	# second method:
	2's, 4's, 8's by dividing a integer then sum up = the number of 2's
	5's, 25's, 125's by dividing a integer then sum up = the number of 5's

*/


/* 1) FIRST METHOD WAY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define smaller(a,b) (a>b?b:a)
int fives, twos;
int NumberOfFive(int from, int to)
{
	int fcount = 0;
	while (from % 5 != 0) from++;
	for (int i = from; i <= to; i+=5) // #From ~ #To
	{
		int x = i;
		while (1)
		{
			if (x % 5 > 0) break;
			fcount++;
			x = x / 5;
		}
	}
	return fcount;
}
int NumberOfTwo(int from, int to)
{
	int tcount = 0;
	if(from % 2 != 0) from++;
	for (int i = from; i <= to; i+=2) // #From ~ #To
	{
		int x = i;
		while (1)
		{
			if (x % 2 > 0) break;
			tcount++;
			x = x / 2;
		}
	}
	return tcount;
}
int main()
{
	int N, M; scanf("%d %d", &N, &M);
	if (M < N - M) { //nCm
		fives = NumberOfFive(N - M + 1, N) - NumberOfFive(5, M);
		twos = NumberOfTwo(N - M + 1, N) - NumberOfTwo(2, M);
	}
	else { //nCn-m
		fives = NumberOfFive(M + 1, N) - NumberOfFive(5,N-M);
		twos = NumberOfTwo(M + 1, N) - NumberOfTwo(2, N-M);
	}	
	printf("%d\n", smaller(fives, twos));
	return 0;
}
*/