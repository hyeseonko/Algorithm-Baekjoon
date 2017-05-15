/* 
	TITLE: PRIME NUMBER
	BAEKJOON 2581
	DATE: 2017-05-15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int M, N;
	int arr[10001];
	int sum = 0;
	int min = 0;
	scanf("%d", &M);
	scanf("%d", &N);

	// M���� N���� arr[i] = i�� �ǵ��� �����
	for (int i = 1; i <= N; i++) arr[i] = i;

	// �����佺�׳׽��� ü ���� �̿��ؼ� ����� �Ǹ�, arr[i]=0�� Set�ϱ�
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= N; j += i) arr[j] = 0;
	}

	// arr[i]=0�� �ƴ�, �� �Ҽ����� �հ� �ּҰ� ����ϱ�
	for (int i = M; i <= N; i++)
	{
		if (arr[i] >1) // 1�� ��쵵 �Ҽ����� ���ܽ�Ű��.
		{
			if (sum == 0) min = arr[i];
			sum += arr[i];
		}
	}
	if (sum == 0) puts("-1"); // sum�� 0�ΰ� �Ҽ��� �ϳ��� ���ٴ� ��
	else printf("%d\n%d\n", sum, min);
	return 0;
}