#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int>v;

int bs(int l,int r,int k,int b,vector<int> &v){
    int most_left=l;
    int mx=0;
    while(l<=r){
        int m=(l+r)/2;
        int tmp=v[m]-v[most_left-1]+(m-most_left+1)*k;
        if(tmp==b)return v[m]-v[most_left-1];
        if(tmp>b)r=m-1;
        if(tmp<b){
            l=m+1;
            mx=max(mx,v[m]-v[most_left-1]);
        }
    }
    return mx;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    v.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }
    while(m--){
        int l,b;
        cin>>l>>b;
        l++;
        cout<<bs(l,n,k,b,v)<<'\n';
    }
}