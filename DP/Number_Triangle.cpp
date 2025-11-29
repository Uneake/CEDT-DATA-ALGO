#include <bits/stdc++.h>
using namespace std;

int n,mx=-1;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int tmp;cin>>tmp;
            v[i].push_back(tmp);
            int up= (i-1 >= 0&&j<i ? v[i-1][j] : 0);
            int left=(i-1>=0&&j-1>=0 ? v[i-1][j-1]:0);
            v[i][j]+=max(up,left);
            mx=max(mx,v[i][j]);
        }
    }
    cout<<mx;
}