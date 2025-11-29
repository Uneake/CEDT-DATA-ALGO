#include <bits/stdc++.h>
using namespace std;

int t;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<double>>v(n,vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>v[i][j];
        }
        bool cycle=false;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j]=max(v[i][j],v[i][k]*v[k][j]);
                    if(i==j&&v[i][j]!=1.0){
                        cycle=true;
                        break;
                    }
                }
                if(cycle)break;
            }
            if(cycle)break;
        }
        if(cycle)cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}