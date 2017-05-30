/*
	TITLE: THE DRUNK JAILER
	BAEKJOON 6359
	2002 GREATER NEW YORK PROGRAMMING CONTEST #B
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-30

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
bool rooms[101];
int main()
{
	int T; scanf("%d", &T); //testcase
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				if (rooms[j]) rooms[j] = false;
				else rooms[j] = true;
			}
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (rooms[i]) count++;
		}
		printf("%d\n", count);
		memset(rooms, false, sizeof(rooms));
	}
	return 0;
}
/* HOW I SOLVED THIS */
/*
	using bool rooms[x] setting false if it's closed, true if it's open
	then finally, count the number of rooms[x] which is true.
	Then this is the answer!
*/