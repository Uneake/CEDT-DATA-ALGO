#include <bits/stdc++.h>
using namespace std;

set<string>se;
bool DIVOC(int left,int right, string & s){
    bool termin= (abs(left-right)==2);
    if(termin&&s[left-(left>right)]=='0'&&s[right-(right>left)]=='1'){
        return true;
    }
    if(termin)return false;
    //cout<<"l : "<<left<<" r : "<<right<<'\n';
    int mid=(left+right)/2;
    return (DIVOC(left,mid,s)||DIVOC(mid,left,s))&&DIVOC(mid,right,s);
}

int n,k;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    int sz=1<<k;
    string s="";
    for(int i=0;i<sz/2;i++)s+="01";
    while(n--){
        string tmp="";
        for(int i=0;i<sz;i++){
            char c;
            cin>>c;
            tmp+=c;
        }
        if(DIVOC(0,sz,tmp))cout<<"yes\n";
        else cout<<"no\n";
    }
}


