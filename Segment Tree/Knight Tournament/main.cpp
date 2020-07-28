/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/


#include <bits/stdc++.h>
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

void updateTree(vector<int>&tree, int index, int L, int R, int l, int r, int value) {
	if (r < L || l > R || (tree[index] != -1)) {
		return;
	} if (L == R) {
		if (L != value) {
			tree[index] = value;
		}
		return;
	}

	int mid = (L + R) / 2;
	updateTree(tree, 2 * index, L, mid, l, r, value);
	updateTree(tree, 2 * index + 1, mid + 1, R, l, r, value);

	if ((tree[2 * index] != -1) && (tree[2 * index + 1] != -1)) {
		tree[index] = value;
	}
	return;
}

void fillVector(vector<int>&tree, vector<int>&ans, int L, int R, int index) {
	if (L == R) {
		ans[L] = tree[index] + 1;
		return;
	}
	int mid = (L + R) / 2;
	fillVector(tree, ans, L, mid, 2 * index);
	fillVector(tree, ans, mid + 1, R, 2 * index + 1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int n, q;
	cin >> n >> q;
	vector<int> tree(4 * n + 5, -1);
	// -1 denotes that the soldiers are not dead
	while (q--) {
		int l, r, v;
		cin >> l >> r >> v;
		updateTree(tree, 1, 0, n - 1, l - 1, r - 1, v - 1);
	}
	vector<int> ans(n);
	fillVector(tree, ans, 0, n - 1, 1);
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {cout << 0 << " ";}
		else {cout << ans[i] << " ";}
	} cout << endl;
	return 0;
}