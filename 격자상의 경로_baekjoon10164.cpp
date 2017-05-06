#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Combination(int n, int m);

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	if (K == 0) 
		printf("%d\n", Combination(N + M - 2, N - 1)); // 우변이 M-1여도 값은 같다. 연산을 더 줄이고싶으면 N,M중 작은걸로 넣으면됨.
	
	else  // K가 0이 아닐때
	{
		int q = (K - 1) / M;         // quotient
		int r = (K - 1) % M;         // remainder
		printf("%d\n", Combination(q + r, q)*Combination(N+M - q - r - 2, N - q - 1));
	}
	return 0;
}


// Combination이 Factorial계산이니까 연산최소화해보장.
int Combination(int n, int m) 
{
	int result = 1;
	for (int i = 1; i <=m; i++)
	{
		result *= n;
		result /= i;
		n--;
	}
	return result;
}