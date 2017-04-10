#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>

using namespace std;

void checkRight(char *str, int length)
{
	int x=0, y=0, z=0, w=0;
	for (int k = 0; k < length; k++)
	{
		switch (str[k]) {
		case '(': x++; break;
		case ')': y++; break;
		case '[': z++; break;
		case ']': w++; break;
		}
		if ((str[k] == '('&&str[k+1] == ']') || (str[k] == '['&&str[k + 1] == ')'))
		{
			puts("0"); exit(-1);
		}
	}
	if ((x != y) || (z != w))
	{
		puts("0"); exit(-1);
	}
}

int main()
{
	char command[31];      // 입력 받을 변수
	int len;
	int temp1, temp2;
	int result = 0;        // 최종 원하는 결과 값
	stack<int> st;        // Stack 

	scanf("%s", command);
	len = strlen(command);

	checkRight(command, len);  // 올바른 문자열인지 검사

	for (int i = 0; i < len; i++)
	{		
		if (command[i] == '(')		st.push(1);
		
		else if (command[i] == '[')	st.push(0);
		
		else if (command[i] == ')')
		{
			if (st.top() == 1) {
				st.pop();
				st.push(2);
			}
			else {
				temp1 = 0;
				while (st.top() != 1)
				{
					temp1 += st.top();
					st.pop();
				}
				st.pop();
				st.push(temp1 * 2);
			}
		}
		else if (command[i] == ']')
		{
			if (st.top() == 0)
			{
				st.pop();
				st.push(3);
			}
			else {
				temp2 = 0;
				while (st.top() != 0)
				{
					temp2 += st.top();
					st.pop();
				}
				st.pop();
				st.push(temp2 * 3);
			}
		}
	}
	int size = st.size();
	for (int j = 0; j < size; j++)
	{
		result += st.top();
		st.pop();
	}
	printf("%d", result);
	return 0;
}