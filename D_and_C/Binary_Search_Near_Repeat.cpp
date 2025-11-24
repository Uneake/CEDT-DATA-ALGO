#include <bits/stdc++.h>
using namespace std;

int n,m,t,x;
vector<int>v;

int bs(int l,int r,int val,vector<int> & v){
    int mx=0;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]>val)r=m-1;
        else if(v[m]<=val){
            l=m+1;
            if(mx<m){
                mx=m;
            }
        }
    }
    if(v[mx]<=val)return mx;
    return -1;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    while (m--){
        cin>>x;
        cout<<bs(0,n-1,x,v)<<'\n';
    }
    
}