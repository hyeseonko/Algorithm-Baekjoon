/*
	TITLE: GET SUM OF SOME PARTS
	BAEKJOON 2042
	CATEGORY: SEGMENTATION TREE
	DATE: 2017-08-23

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>
#define ll long long 

using namespace std;

ll Init(vector<ll> &arr, vector<ll> &tree, int tree_num, int s, int e)
{
	if (s == e) return tree[tree_num] = arr[s];
	int mid = (s + e) / 2;
	return tree[tree_num] = Init(arr, tree, tree_num * 2, s, mid) + Init(arr, tree, tree_num * 2 + 1, mid + 1, e);
}

void Change(vector<ll> &arr, vector<ll> &tree, int tree_num, int s, int e, int idx, int what)
{
	if (!(s <= idx&&idx <= e)) return;
	tree[tree_num] += what;
	if (s != e)
	{
		int mid = (s + e) / 2;
		Change(arr, tree, tree_num * 2, s, mid, idx, what);
		Change(arr, tree, tree_num * 2 + 1, mid + 1, e, idx, what);
	}
}

ll Sum(vector<ll> &tree, int tree_num, int s, int e, int l, int r)
{
	if (l > e || r < s) return 0;
	if (l <= s&&e <= r) return tree[tree_num];
	int mid = (s + e) / 2;
	return Sum(tree, tree_num * 2, s, mid, l, r) + Sum(tree, tree_num * 2 + 1, mid + 1, e, l, r);
}


int main()
{
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	int temp = (int)ceil(log2(N));
	int segtree_size = 1 << (temp+1); // pow(2,temp+1)
	
	vector<ll> arr(N);
	vector<ll> tree(segtree_size);

	for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
	Init(arr, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
		if (a == 1)
		{
			Change(arr, tree, 1, 0, N - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if (a == 2)  printf("%lld\n", Sum(tree, 1, 0, N - 1, b - 1, c - 1));
	}
	return 0;
}