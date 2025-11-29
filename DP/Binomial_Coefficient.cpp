#include <bits/stdc++.h>
using namespace std;

int bino(int n,int r,vector<vector<int>> & v){
    if(r==n)return 1;
    if(r==0)return 1;
    if(v[n][r]!=-1)return v[n][r];
    v[n][r] = bino(n-1,r,v)+bino(n-1,r-1,v);
    return v[n][r];
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,r;cin>>n>>r;
    vector<vector<int>>v(n+1,vector<int>(r+1,-1));
    cout<<bino(n,r,v);
}