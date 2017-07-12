/*
	TITLE: IRON PIPE
	BAEKJOON 10799
	Olympiad > KOI > MIDDLE SCHOOL #02
	CATEGORY: STACK
	DATE: 2017-07-12
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char arr[100001];
stack <int> st;
int laser[50000];
int pole[50000][2];

int main()
{
	scanf("%s", arr);
	int laser_cur = 0;
	int pole_cur = 0;
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '(')	st.push(i);
		else if (arr[i] == ')')
		{
			if (i >= 1 && arr[i - 1] == '(')
			{
				laser[laser_cur] = i;
				laser_cur++;
			}
			else
			{
				pole[pole_cur][0] = st.top();
				pole[pole_cur][1] = i;
				pole_cur++;
			}
			st.pop();	
		}
	}

	int sum = 0;
	for (int i = 0; i < pole_cur; i++)
	{
		int temp = 1;
		for (int j = 0; j < laser_cur; j++)
		{
			if (pole[i][0] <= laser[j] && laser[j] <= pole[i][1])	temp++;
		}
		sum += temp;
	}
	printf("%d\n", sum);	return 0;
}