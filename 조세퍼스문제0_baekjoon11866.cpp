#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
queue <int> q;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) q.push(i);
	int count = 0;
	printf("<");
	while (!q.empty())
	{
		count++;
		if (count%M == 0) {
			if (q.size() == 1) printf("%d", q.front());
			else printf("%d, ", q.front());
			q.pop();
		}
		else {
			int data = q.front();
			q.pop();
			q.push(data);
		}
	}
	printf(">\n"); return 0;
}