/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Problem : https://codeforces.com/problemset/problem/510/C
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

class Graph {
    int n;
    vector<int> *adj;
public:
    Graph(): n(26) {
        adj = new vector<int>[26];
    }

    void addEdge(char a, char b) {
        adj[a - 'a'].pb(b - 'a');
    }

    bool dfsHelper(int src, vector<bool>&visited, vector<bool>&recStack, string&ans) {
        visited[src] = true;
        recStack[src] = true;
        for (int x : adj[src]) {
            if (recStack[x]) {return true;}
            if (!visited[x] && dfsHelper(x, visited, recStack, ans)) {
                return true;
            }
        }
        ans.push_back(src + 'a');
        recStack[src] = false;
        return false;
    }

    string findOrder() {
        vector<bool> visited(26, false);
        vector<bool> recStack(26, false);
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && dfsHelper(i, visited, recStack, ans)) {
                ans = "Impossible";
                return ans;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    Graph G;
    for (int i = 1; i < n; i++) {
        int j = 0;
        bool b = false;
        for (; (j < (v[i].size())) && (j < (v[i - 1].size())); j++) {
            if (v[i][j] != v[i - 1][j]) {
                G.addEdge(v[i - 1][j], v[i][j]);
                b = true;
                break;
            }
        }
        if (!b) {
            if ((v[i - 1].size()) > (v[i].size())) {
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    cout << G.findOrder() << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ios_base& scientific (ios_base& str);
    solve();
    return 0;
}