#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;
void IsThisPerfect(int n);
queue <int> q;
int main()
{
	/* 예제 입력 */
	int temp;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == -1) break;
		q.push(temp);
	}
	/* Perfect인가 */
	while (!q.empty())
	{
		int target = q.front();
		IsThisPerfect(target);
		q.pop();
	}
	return 0;
}

void IsThisPerfect(int n)
{
	int sum = 1;
	queue <int> divisor_q;
	for (int i = 2; i <= n/2; i++) // 연산횟수를 조금이라도 줄이고자 n이 아닌 n/2를 선택했다.
	{
		if (n%i == 0) { 
			sum += i;
			divisor_q.push(i);
		}
	}
	if (n != sum) {
		printf("%d is NOT perfect.\n", n); 
	}
	else {
		printf("%d = 1", n);
		while (!divisor_q.empty())
		{
			printf(" + %d", divisor_q.front());
			divisor_q.pop();
		}
		printf("\n");
	}
}