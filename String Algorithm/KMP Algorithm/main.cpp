#include <iostream>
#include <string>

using namespace std;

// lps :- longest proper prefix which is also a suffix
//0123456
//aaabbaa
//012
vector<int> generateLPS(string&pat){
    int n=pat.size();
    vector<int> lps(n);
    lps[0]=0;
    int i=1;
    int len=lps[0];
    while(i<n){
        if(pat[i]==pat[len]){
            lps[i]=len+1;
            len=lps[i];
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int strStr(string &txt,string &pat){
    if(pat==""){
        return;
    }
    int n=txt.size();
    int m=pat.size();
    vector<int> lps=generateLPS(pat);
    int i=0;
    int j=0;
    while(i<n){
        if(pat[j]==txt[i])
    }
}

int main(){
    string text,pat;
    cin>>text>>pat;
    
    return 0;
}