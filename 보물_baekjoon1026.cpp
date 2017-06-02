/*
	TITLE: TREASURE
	BAEKJOON 1026
	CATEGORY: SORTING
	DATE: 2017-06-02

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v1;
vector <int> v2;
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		v1.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		v2.push_back(temp);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += v1[N - 1 - i] * v2[i]; // Key point
	}
	printf("%d\n", answer);	return 0;
}
/* HOW I SOLVED THIS */
/*
	since b0,b1,b2,,,,bn is fixed,
	let biggest integer in b_n be = b_t
	then if we multiply b_t by the smallest integer in a_n,
	and with repetition of this step, then we get the answer!

*/