/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <sstream>
#include <string>
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	getline(cin,input);
	stringstream ss(input);
	string token;
	vector<string>tokens;
	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}
	for(string x:tokens){
		cout<<x<<endl;
	}
	return 0;
}