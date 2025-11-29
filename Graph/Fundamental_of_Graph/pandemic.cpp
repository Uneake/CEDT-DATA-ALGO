#include <bits/stdc++.h>
using namespace std;

int r,c,t,co;
queue<pair<pair<int,int>,int>>q;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c>>t;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
            if(v[i][j]==1){
                q.push({{i,j},0});
                v[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto [a,b]=q.front();
        q.pop();
        if(a.first<0||a.first>=r||a.second<0||a.second>=c)continue;
        if(v[a.first][a.second]!=0)continue;
        if(b>t)continue;
        //cout<<b<<' '<<a.first<<' '<<a.second<<endl;
        v[a.first][a.second]=1;
        co++;
        q.push({{a.first+1,a.second},b+1});
        q.push({{a.first-1,a.second},b+1});
        q.push({{a.first,a.second+1},b+1});
        q.push({{a.first,a.second-1},b+1});
    }
    cout<<co;
}