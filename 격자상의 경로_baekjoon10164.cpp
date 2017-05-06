#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Combination(int n, int m);

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	if (K == 0) 
		printf("%d\n", Combination(N + M - 2, N - 1)); // �캯�� M-1���� ���� ����. ������ �� ���̰������ N,M�� �����ɷ� �������.
	
	else  // K�� 0�� �ƴҶ�
	{
		int q = (K - 1) / M;         // quotient
		int r = (K - 1) % M;         // remainder
		printf("%d\n", Combination(q + r, q)*Combination(N+M - q - r - 2, N - q - 1));
	}
	return 0;
}


// Combination�� Factorial����̴ϱ� �����ּ�ȭ�غ���.
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