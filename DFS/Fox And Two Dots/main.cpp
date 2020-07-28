/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Question Link : http://codeforces.com/problemset/problem/510/B * 
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

bool isValid(vector<string>&mat, int i, int j, int ch) {
    int n = mat.size();
    int m = mat[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || ch != mat[i][j]) {
        return false;
    } return true;
}

bool dfsHelper(vector<string>&mat, vector<vector<bool> >&visited, int i, int j, int p_i, int p_j) {
    visited[i][j] = true;
    int row[] = { -1, 1, 0, 0};
    int col[] = { 0, 0, -1, +1};
    for (int k = 0; k < 4; k++) {
        int x = i + row[k];
        int y = j + col[k];
        if (x == p_i && y == p_j) {continue;}
        if (isValid(mat, x, y, mat[i][j])) {
            if (visited[x][y] || dfsHelper(mat, visited, x, y, i, j)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (dfsHelper(mat, visited, i, j, -1, -1)) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ios_base& scientific (ios_base& str);
    solve();
    return 0;
}