/*
	TITLE: PENTAGON
	BAEKJOON 1964
	CATEGORY: MATH
	DATE: 2017-05-30

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main()
{
	long long N; scanf("%lld", &N);
	printf("%lld\n", ((N + 1)*(3 * N + 2) / 2) % 45678);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	1) MATHEMATICAL SOLUTION BY SOLVING RECURRENCE RELATION
	a[n]=a[n-1]+3n+1 ..... (*)
	By solving (*), we can directly solve for a[n]
	a[n]=(n+1)*(3n+2)/2;

	DISADVANTAGE: since the range of N is until 10,000,000. we need to define N by using long long



	2) ANOTHER SOLUTION IS USING DYNAMIC PROGRAMMING 
	
	for (int i = 1; i < N; i++)	dp[i] = ((dp[i - 1]) % 45678 + (3 * i + 4) % 45678)%45678;
	printf("%d\n", dp[N - 1]);

	DISADVANTAGE OF 2): IT TOOK LONGER TIME.
*/
/*  SUMMARY

	1) INT: -2 x 10^9 ~ 2 x 10^9 (%d)
	2) LONG LONG: -9 x 10^18 ~ 9 x 10^18 (%lld)

*/