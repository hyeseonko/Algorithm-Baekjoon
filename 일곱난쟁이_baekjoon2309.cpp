#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main()
{
	int arr[9]; int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100) {
				int k = 0;
				while (k < 9)
				{
					if (k != i && k != j) v.push_back(arr[k]);
					k++;
				}
				sort(v.begin(), v.end());
				for (int i = 0; i < 7; i++) printf("%d\n", v[i]);
				return 0;
			}
		}
	}

}