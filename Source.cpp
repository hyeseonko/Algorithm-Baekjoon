#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <utility>
#include <stdio.h>

using namespace std;

int isThereBiggerOne(queue <pair<int,int>> testq)
{
	int yes = 0;
	int one = testq.front().first;

	while (!testq.empty())	{
		if (testq.size() == 1) break;
		testq.pop();

		if (one < testq.front().first) {
			yes++;
			break;
		}
	}
	if (yes > 0) return 1;
	else return 0;
}

int main()
{
	int test_case;
	int command[100];
	int num, idx;
	int result;
	queue <pair <int, int>> q;

	scanf("%d", &test_case);   // Test_case 횟수
	
	for (int i = 1; i <= test_case; i++)
	{
		result = 0;
		scanf("%d %d", &num, &idx);

		for (int j = 0; j < num; j++)
		{
			scanf("%d", &command[j]);
			q.push({ command[j], j });
		}

		while (!q.empty())
		{
			if (!isThereBiggerOne(q))      // q.front()가 제일 크면
			{
				result++;
				if (q.front().second == idx) 	break;
				q.pop();
			}

			else {                  // q.front()보다 큰 것이 존재하면.
				q.push(q.front());
				q.pop();
			}
		}
		while (!q.empty())	q.pop();
		printf("%d\n", result);
	}


	return 0;
}


