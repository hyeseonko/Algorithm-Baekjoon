/*
	TITLE: MOVES
	BAEKJOON 11048
	CATEGORY: DYNAMIC PROGRAMMING
	DATE: 2017-05-31
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[1000][1000];
int arr[1000][1000];
int bigger(int a, int b){
	if (a > b) return a;
	else return b;
}
int main()
{
	// INPUT
	int N, M; scanf("%d %d", &N, &M); 
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	scanf("%d", &arr[i][j]);

	/* Initialization */
	dp[0][0] = arr[0][0];
	for (int i = 1; i < N; i++)	dp[i][0] = arr[i][0] + dp[i - 1][0]; // FIRST COLUMN
	for (int j = 1; j < M; j++)	dp[0][j] = arr[0][j] + dp[0][j - 1]; // FIRST ROW
	for (int i = 1; i < N; i++)	{
		for (int j = 1; j < M; j++){
			dp[i][j] = arr[i][j] + bigger(bigger(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}
	printf("%d\n", dp[N - 1][M - 1]);
	return 0;
}
/* HOW I SOLVED THIS */
/*
	USING DYNAMIC PROGRAMMING
	
	dp[x][y], the largest amount of candy I can get
	can be deduced from the biggest among dp[x-1][y], dp[x][y-1], dp[x-1][y-1]

*/