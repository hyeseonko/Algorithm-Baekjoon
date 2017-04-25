/*
이문제를 시간초과로 많이 틀렸는데 그 이유가 정수형 범위 때문이다.
큰 범위의 문제는 되도록 정수형 범위에 신경쓰도록 하자!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned long long num;
	scanf("%llu", &num);
	unsigned long long n = 1;
	while (1)
	{
		if (num<(n + 1)*(n + 2) / 2)
		{
			printf("%llu\n", n);
			break;
		}
		n++;
	}
	return 0;
}