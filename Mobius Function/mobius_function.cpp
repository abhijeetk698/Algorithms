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
#define MAX 100001

int mobius[MAX], prime_count[MAX], a[MAX];

void fillMobius() {
	for (int i = 0; i < MAX; i++) {
		a[i] = 1;
	}

	for (int i = 2; i < MAX; i++) {
		if (prime_count[i]) {continue;}
		for (int j = i; j < MAX; j += i) {
			prime_count[j]++;
			a[j] *= i;
		}
	}

	for (int i = 1; i < MAX; i++) {
		if (a[i] == i) {
			if (prime_count[i] & 1) {
				mobius[i] = -1;
			} else {
				mobius[i] = 1;
			}
		} else {
			mobius[i] = 0;
		}
	}

	return ;
}

void solve(){
	fillMobius();
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		cout<<mobius[i]<<" ";
	}
	return ;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	solve();
	return 0;
}