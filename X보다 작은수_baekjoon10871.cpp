#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
	int N, X, temp;
	queue <int> q;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp < X) q.push(temp);
	}
	while (!q.empty())
	{
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
	return 0;
}