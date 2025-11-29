#include <bits/stdc++.h>
using namespace std;

int v,e,k,mx=-1;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>v>>e>>k;
    vector<vector<int>>G(v);
    while(e--){
        int st,en; cin>>st>>en;
        G[st].push_back(en);
        G[en].push_back(st);
    }
    for(int i=0;i<v;i++){
        vector<bool>visit(v,false);
        int co=0;
        queue<pair<int,int>>q;
        q.push({i,0});
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            if(visit[a])continue;
            visit[a]=true;
            co++;
            if(b+1>k)continue;
            for(auto V:G[a]){
                if(visit[V])continue;
                q.push({V,b+1});
            }
        }
        mx=max(mx,co);
    }
    cout<<mx;
}