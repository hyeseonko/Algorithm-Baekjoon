/*
	TITLE: GOLDBACH'S CONJECTURE
	BAEKJOON 9020
	DAEJEON NATIONALWIDE INTERNET COMPETITION 2011 #E	
	DATE: 2017-05-20

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num[10001];
int prime[1230]; // the max num of primes until 10,000
int main()
{
	int x, y;
	int T; scanf("%d", &T); // TestCase
	while (T--)
	{
		int n; scanf("%d", &n);
		int prime_num = 0;
		for (int i = 2; i <= n; i++) num[i] = i;
		for (int i = 2; i <= (n / 2); i++)
		{
			for (int j = i + i; j <= n; j += i) num[j] = 0;
		}
		for (int i = 2; i < n; i++)
		{
			if (num[i] != 0) { 
				prime[prime_num] = num[i]; 
				prime_num++;
			}
		}
		int arr[2] = { 0,9999 };
		for (x = 0; x < prime_num; x++)
		{
			for (y = x; y < prime_num; y++)
			{
				if (prime[x] + prime[y] == n)
				{
					if (prime[y] - prime[x] < arr[1] - arr[0])
					{
						arr[0] = prime[x];
						arr[1] = prime[y];
					}
				}
			}
		}
		printf("%d %d\n", arr[0], arr[1]);
	}
	return 0;
}