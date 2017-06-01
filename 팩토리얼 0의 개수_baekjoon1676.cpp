/*
	TITLE: THE NUMBER OF 0 IN N!
	BAEKJOON 1676
	CATEGORY: MATH
	DATE: 2017-06-02

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	int count = 0;
	if (N == 0) puts("1");
	else {
		for (int i = 1; i <= N; i++)
		{
			if (i % 5 == 0) {
				count++;
				if ((i / 5) % 5 == 0)
				{
					count++;
					if ((i / 25) % 5 == 0) count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
/* HOW I SOLVED THIS */
/*
	To count 0s in n factorial means that 
	how many 2, 5 are there!
	but 2 occurs more compared to 5 because 2 occurs every two number
	So, here, we don't need to calculate for number 2.
	we can only consider how many 5 does exist in the number!!
	Then, it became simplified.
*/