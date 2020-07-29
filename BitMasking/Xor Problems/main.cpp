/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Problem Link : https://www.hackerrank.com/contests/codeagon/challenges/xor-queries/problem
******************************************/


#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll setIthBit(ll int y,ll int i,ll int val){
    ll int temp=0;
    if(val==1){
        temp=(y|((ll)1<<i));
    }else{
        temp=(y&(~((ll)1<<(ll)i)));
    }return temp;
}

void solve(){
    ll int x,l,r;
    cin>>x>>l>>r;
    ll int y=0;
    for(int i=60;i>=0;i--){
        ll int val=(x&((ll)(1)<<(ll)i));
        if(val>0){
            ll int Min=setIthBit(y,i,0);
            ll int Max=setIthBit(y,i,1)-1;
            if(Max<l || Min>r){
                y=setIthBit(y,i,1);
            }else{
                y=setIthBit(y,i,0);
            }
        }else{
            ll int Min= setIthBit(y,i,1);
            ll int Max=Min+setIthBit(0,i,1)-1;
            if(Max<l || Min>r){
                y=setIthBit(y,i,0); 
            }else{
                y=setIthBit(y,i,1);
            }
        }
    }
    cout<<(y^x)<<endl;
    return ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}