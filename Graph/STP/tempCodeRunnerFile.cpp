#include <bits/stdc++.h>
using namespace std;
using pll=pair<long long,long long>;

int n,w,en,k;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>w;
    vector<vector<pll>>G(n+1);
    vector<long long>dist(n+1,LLONG_MAX);
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    G[1].push_back({w,2});
    G[2].push_back({w,1});
    for(int i=3;i<=n;i++){
        cin>>k;
        while (k--){
            cin>>en>>w;
            G[en].push_back({w,i});
            G[i].push_back({w,en});
        }
        vector<bool>visit(n+1,false);
        pq.push({0,1});
        dist[1]=0;
        visit[1]=true;
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            visit[u]=true;
            for(auto [c,v]:G[u]){
                if(dist[v]>c+w&&!visit[v]){
                    dist[v]=c+w;
                    pq.push({dist[v],v});
                }
            }
        }
        cout<<dist[2]<<' ';
    }
}