#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int>v;

int DIVOC2(int l,int r, vector<int> & v){
    if(abs(l-r)==1)return v[l];
    int m=(l+r)/2;
    int co_l = DIVOC2(l,m,v);
    int co_r = DIVOC2(m,r,v);
    if(co_l==-1||co_r==-1)return -1;
    if(abs(co_l-co_r)<=1)return co_l+co_r;
    else return -1;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    int sz=1<<k;
    v.resize(sz);
    while(n--){
        for(int i=0;i<sz;i++)cin>>v[i];
        if(DIVOC2(0,sz,v)!=-1)cout<<"yes\n";
        else cout<<"no\n";
    }
}