#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n)),mss(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>v[i][j];
    }
    int ans=v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                mss[i][j]=v[i][j];
                continue;
            }
            mss[i][j]=max(v[i][j],mss[i-1][j-1]+v[i][j]);
            ans=max(ans,mss[i][j]);
        }
    }
    cout<<ans;
}