/* ������ ������ �Ѿ �� ū ���� ����ϰ� ������
	unsigned long long (format: llu)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	printf("%llu\n", (n*n*n - n) / 2);
	return 0;
}