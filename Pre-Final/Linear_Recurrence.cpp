#include <bits/stdc++.h>
using namespace std;
const int MOD=32717;

int R(int n,int k,vector<int> & c,vector<int> & v){
    if(v[n]!=-1)return v[n]%MOD;
    int sum=0;
    for(int i=1;i<=k;i++){
        sum = (sum%MOD + ((c[i]%MOD)*(R(n-i,k,c,v)%MOD)%MOD))%MOD;
    }
    v[n]=sum%MOD;
    return sum%MOD;
}

int n,k;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k>>n;
    vector<int>v(n+1,-1);
    vector<int>c(k+1);
    for(int i=1;i<=k;i++)cin>>c[i];
    for(int i=0;i<k;i++)cin>>v[i];
    cout<<R(n,k,c,v);
}