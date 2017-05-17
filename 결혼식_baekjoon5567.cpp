/*
	TITLE: WEDDING
	BAEKJOON 5567
	DATE: 2017-05-17
	JOI 2010 #03

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ppl[501][501]; //people
bool checked[501]; 
int main()
{
	/* INPUT */
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	while (M--){
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		if(tmp1!=tmp2) ppl[tmp1][tmp2] = ppl[tmp2][tmp1] = 1; // 같은값은 무시
	}
	/* FUNCTION */

	for (int i = 2; i <= N; i++)
	{
		if (ppl[i][1] == 1) {            // 1과 연결된 경우만 카운트하겠따.
			checked[i] = true;
			for (int j = 2; j <= N; j++) {
				if (ppl[i][j] == 1) {
					checked[j] = true;
				}
			}
		}
	}
	int count = 0;
	for (int i = 2; i <= N; i++) if (checked[i] == true) count++;
	printf("%d\n", count);
	return 0;
}

/*  틀렸습니다 계속 나왔던이유
	(1,2)(1,3)(3,4)(4,5)(4,1) 순서상관없이 오는 경우 생각해보니 틀린듯
*/