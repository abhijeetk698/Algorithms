/*************************************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Question Link : https://codeforces.com/contest/339/problem/D
**************************************************************/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
// op
// true  : XOR
// false : OR

void BuildTree(vector<int>&tree, vector<int>&v, int index, int L, int R, bool op) {
	if (L == R) {
		tree[index] = v[L];
		return ;
	}
	int mid = (L + R) >> 1;
	BuildTree(tree, v, 2 * index, L, mid, (!op));
	BuildTree(tree, v, 2 * index + 1, mid + 1, R, (!op));
	// if op==true then perform XOR
	if (op) {
		tree[index] = tree[2 * index] ^ tree[2 * index + 1];
	} else { // if op == false then perform or
		tree[index] = tree[2 * index] | tree[2 * index + 1];
	}
	return;
}

void UpdateTree(vector<int>&tree, vector<int>&v, int index, int L, int R, int i, int value, int op) {
	// Case 1 : No Overlap
	if (i > R || i < L) {
		return;
	}

	// Case 2: Complete Overlap
	if (L == R) {
		tree[index] = value;
		return;
	}
	// Case 3 : Partial Overlap
	int mid = (L + R) >> 1;
	UpdateTree(tree, v, 2 * index, L, mid, i, value, (!op));
	UpdateTree(tree, v, 2 * index + 1, mid + 1, R, i, value, (!op));
	if (op) {
		tree[index] = tree[2 * index] ^ tree[2 * index + 1];
	} else {
		tree[index] = tree[2 * index] | tree[2 * index + 1];
	}
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int N = pow(2, n);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<int> tree(4 * N + 5);
	BuildTree(tree, v, 1, 0, N - 1, (n % 2 == 0));
	while (m--) {
		int index, value;
		cin >> index >> value;
		UpdateTree(tree, v, 1, 0, N - 1, index - 1, value, (n % 2 == 0));
		cout << tree[1] << endl;
	}
	return 0;
}