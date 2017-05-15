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

	// M부터 N까지 arr[i] = i가 되도록 만들기
	for (int i = 1; i <= N; i++) arr[i] = i;

	// 에라토스테네스의 체 원리 이용해서 배수가 되면, arr[i]=0로 Set하기
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= N; j += i) arr[j] = 0;
	}

	// arr[i]=0이 아닌, 즉 소수들의 합과 최소값 출력하기
	for (int i = M; i <= N; i++)
	{
		if (arr[i] >1) // 1인 경우도 소수에서 제외시키기.
		{
			if (sum == 0) min = arr[i];
			sum += arr[i];
		}
	}
	if (sum == 0) puts("-1"); // sum이 0인건 소수가 하나도 없다는 것
	else printf("%d\n%d\n", sum, min);
	return 0;
}