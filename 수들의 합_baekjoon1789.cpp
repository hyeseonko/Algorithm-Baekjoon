/*
�̹����� �ð��ʰ��� ���� Ʋ�ȴµ� �� ������ ������ ���� �����̴�.
ū ������ ������ �ǵ��� ������ ������ �Ű澲���� ����!
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