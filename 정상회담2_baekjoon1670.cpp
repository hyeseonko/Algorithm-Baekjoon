/*
	TITLE: SUMMIT
	BAEKJOON 1670
	CATEGORY: MATH + DYNAMIC PROGRAMMING
	DATE: 2017-05-30

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long catalan[10001] = { 1,1, };
void Shaking(int x) {
	for (int i = 2; i <= x; i++) // DYNAMIC
	{
		for (int j = 0; j < i; j++) // CATALAN RECURRENCE RELATION
		{
			catalan[i] += (catalan[j] * catalan[i - 1 - j]) % 987654321;
			catalan[i] = catalan[i] % 987654321;
		}
	}
	printf("%lld\n", catalan[x]);
}
int main() { 
	int N; scanf("%d", &N);	
	Shaking(N / 2); 
	return 0; 
}
/* how I solved this */
/*
	USING CATALAN NUMBER THEORY
	When I started solving this problem, I come up with a catalan number which is 1,2,5,14,,,,!
	and the general term of catalan number is 2nCn / (n+1)
	but I couldn't set this because it exceeds the range of integer since it has a multiplication inside it
	So, I used dynamic programming combined with catalan recurrence relation
	: C[N] = C[0]C[N-1] + C[1]C[N-2] + ... + C[N-1]C[0] 
*/