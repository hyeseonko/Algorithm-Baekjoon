/*
	TITLE: PARENTHESIS
	BAEKJOON 9012
	DAEJEON NATIONALWIDE INTERNET COMPETITION 2012 #G
	CATEGORY: STACK
	DATE: 2017-05-21
	
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <vector>
#include <string.h> //memset
#include <stack>
using namespace std;
char arr[51];
stack <int> st;
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", arr);
		int len = strlen(arr);
		for(int j=0;j<len;j++)
		{
			if (arr[j] == '(')	st.push(1);
			else if (arr[j] == ')') 
			{
				if (!st.empty()&&st.top() == 1) st.pop();
				else st.push(2); 
			}
		}
		if (st.size() == 0) puts("YES");
		else if (st.size() > 0) { puts("NO"); while (!st.empty()) st.pop(); }
		memset(arr, NULL, sizeof(arr));
	}
	return 0;
}