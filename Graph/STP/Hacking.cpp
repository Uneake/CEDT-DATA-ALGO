#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int n,m,k,T=-1;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    vector<int>c(n);
    vector<int>st(k);
    vector<int>dist(n,INT_MAX);
    vector<vector<int>>G(n);
    vector<bool>visit(n,false);
    for(int i=0;i<k;i++)cin>>st[i];
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<m;i++){
        int start,en;
        cin>>start>>en;
        G[start].push_back(en);
        G[en].push_back(start);
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(auto x:st){
        pq.push({c[x],x});
        dist[x]=c[x];
    }
    while(!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        if(visit[u])continue;
        visit[u]=true;
        T=max(T,w);
        for(auto v:G[u]){
            if(dist[v]>w+c[v]&&!visit[v]){
                dist[v]=w+c[v];
                pq.push({dist[v],v});
            }
        }
    }
    cout<<T;
}