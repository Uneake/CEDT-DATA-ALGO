#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    cin>>n>>m;
    
    vector<int>co(n);
    vector<int>ci(n);
    for(int i=0;i<n;i++)cin>>ci[i];
    for(int i=0;i<n;i++)cin>>co[i];

    vector<vector<int>>G(n);
    vector<int>dist(n,INT_MAX);
    vector<bool>visit(n,false);
    for(int i=0;i<m;i++){
        int st,en;
        cin>>st>>en;
        G[st].push_back(en);
    }

    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,0});
    dist[0]=0;
    while (!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        visit[u]=true;
        for(auto v:G[u]){
            if(dist[v]>w+co[u]+ci[v]&&!visit[v]){
                dist[v]=w+co[u]+ci[v];
                pq.push({dist[v],v});
            }
        }
    }
    for(auto w:dist)cout<<((w==INT_MAX) ? -1:w)<<' ';
}