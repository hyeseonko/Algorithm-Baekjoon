/*
	TITLE: STACK SEQUENCE
	BAEKJOON 1974
	CATEGORY: STACK
	DATE: 2017-07-11

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

using namespace std;

stack <int> st;
int arr[100000];
char ans[200001];

int main()
{
	int N; scanf("%d", &N); // INPUT
	
	int num = 1;
	int cur = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (st.empty())
		{
			st.push(num);
			num++;
			ans[cur] = '+';
			cur++;
		}
		if (arr[i] < st.top())
		{
			puts("NO");
			return 0;
		}
		if (arr[i] > st.top())
		{
			while (arr[i] != st.top())
			{
				st.push(num);
				num++;
				ans[cur] = '+';
				cur++;
			}
		}
		if (st.top() == arr[i])
		{
			st.pop();
			ans[cur] = '-';
			cur++;
		}
	}
	for (int i = 0; i < cur; i++) 	printf("%c\n", ans[i]);
	return 0;
}