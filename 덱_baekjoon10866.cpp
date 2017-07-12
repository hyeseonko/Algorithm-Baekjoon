/*
	TITLE: DEQUE
	BAEKJOON 10866
	CATEGORY: DEQUE
	DATE: 2017-07-12
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>    // strncmp
#include <stdlib.h>  // atoi
#include <deque>

using namespace std;
deque <int> dq;
char command[16];

int main()
{
	int N; scanf("%d", &N); // 명령의 수
	getchar();				// 엔터를 버퍼에서 비우기 위해 씀
	while (N--)
	{
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';     //fgets는 마지막에 '\n'이 들어가서 이를 널로 대체한다.
		if (!strncmp(command, "push_front", 10))
		{
			int numcommand = atoi(&command[11]);
			dq.push_front(numcommand);
		}
		else if (!strncmp(command, "push_back", 9))
		{
			int numcommand = atoi(&command[10]);
			dq.push_back(numcommand);
		}
		else if (!strncmp(command, "pop_front", 9))
		{
			if (dq.empty())	puts("-1");
			else
			{
				int num = dq.front();
				printf("%d\n", num);
				dq.pop_front();
			}
		}
		else if (!strncmp(command, "pop_back", 8))
		{
			if (dq.empty())	puts("-1");
			else
			{
				int num = dq.back();
				printf("%d\n", num);
				dq.pop_back();
			}
		}
		else if (!strncmp(command, "size", 4))
		{
			printf("%d\n", dq.size());
		}
		else if (!strncmp(command, "empty", 5))
		{
			if (dq.empty()) puts("1");
			else puts("0");
		}
		else if (!strncmp(command, "front", 5))
		{
			if (dq.empty()) puts("-1");
			else printf("%d\n", dq.front());
		}
		else if (!strncmp(command, "back", 4))
		{
			if (dq.empty()) puts("-1");
			else printf("%d\n", dq.back());
		}
	}
	return 0;
}
/* 깨달음 */
/*
	scanf로 N받고 엔터가 그다음 문자열입력할때 인식 되어버린다.
	>> 해결 using getchar();
*/