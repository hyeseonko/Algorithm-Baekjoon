/*
	TITLE: PINARY NUMBER
	BAEKJOON 2193
	CATEGORY: DYNMAIC PROGRAMMING
	DATE: 2017-05-29
	I think this problem is solving fibonacci number
	the reason why:
	Let Z(n)=Length N ending with zero(0)
	Let O(n)=Length N ending with one(1)
	Let T(n)=The total number of Length N = Z(n)+O(n)
	Then Z(n)=O(n-1)+Z(n-1)
	Then O(n)=Z(n-1)=T(n-2)
	Z(n)+O(n)=Z(n-1)+O(n-1)+T(n-2)
	Therefore, T(n)=T(n-1)+T(n-2) with initial conditions T(1)=1, T(2)=1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long dp[90];
int main()
{
	int N; scanf("%d", &N); // INPUT
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[N - 1]);
	return 0;
}