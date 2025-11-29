#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long,long>;

ll n,w;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vector<vector<pll>>v(n);
    vector<ll>dist(n,LLONG_MAX);
    vector<bool>visit(n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w;
            if(w>0)v[i].push_back({w,j});
        }
    }
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({0,0});
    dist[0]=0;
    visit[0]=true;
    while (!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        visit[u]=true;
        for(auto [c,v]:v[u]){
            if(w+c<dist[v]&&!visit[v]){
                dist[v]=w+c;
                pq.push({w+c,v});
            }
        }
    }
    bool ch=false;
    ll mx=-1;
    for(int i=0;i<n;i++){
        if(dist[i]==LLONG_MAX){
            ch=true;
            break;
        }
        mx=max(mx,dist[i]);
    }
    if(!ch)cout<<mx;
    else cout<<-1;
}