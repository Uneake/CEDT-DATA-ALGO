#include <bits/stdc++.h>
using namespace std;

const int MOD=1e6+3;
int n,k;

int split(int n,vector<int> & v,vector<int> & dp){
    if(n<0)return 0;
    if(dp[n]!=0)return dp[n];
    for(auto & val:v)dp[n]=(dp[n]%MOD+(split(n-val,v,dp))%MOD)%MOD;
    return dp[n];
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    vector<int>v(k),dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=0;i<k;i++)cin>>v[i];
    cout<<split(n,v,dp);
}