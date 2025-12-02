#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r,c; cin>>r>>c;
    vector<vector<int>> qs(r+1,vector<int>(c+1,0));
    vector<vector<int>>pascal_tri(1001,vector<int>(1001,0));
    for(int i=0;i<=1000;i++){
        pascal_tri[i][0]=1;
        pascal_tri[i][i]=1;
    }
    for(int i=2;i<=1000;i++){
        for(int j=1;j<i;j++)pascal_tri[i][j]=(pascal_tri[i-1][j]%M+pascal_tri[i-1][j-1]%M)%M;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            char t;cin>>t;
            int plus=0;
            if(t=='a')plus=1;
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+plus;
        }
    }
    int q; cin>>q;
    while(q--){
        int r1,r2,c1,c2,k;
        cin>>r1>>c1>>r2>>c2>>k;
        int all=qs[r2][c2]-qs[r1-1][c2]-qs[r2][c1-1]+qs[r1-1][c1-1];
        if(k>all)cout<<-1;
        else cout<<pascal_tri[all][k];
        cout<<'\n';
    }
}