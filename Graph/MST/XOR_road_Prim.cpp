#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;

ull n,co;
priority_queue<pair<ull,ull>>pq;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vector<ull>v;
    vector<bool>visit(n,false);
    vector<ull>cost(n,0);
    for(ull i=0;i<n;i++){
        ull a;cin>>a;
        v.push_back(a);
    }
    pq.push({0,0});
    visit[0]=true;
    cost[0]=0;
    while(!pq.empty()){
        auto [c,u]=pq.top();
        pq.pop();
        visit[u]=true;
        for(int i=0;i<n;i++){
            if(i==u)continue;
            ull tmp=v[i]^v[u];
            if(tmp>cost[i]&&!visit[i]){
                co-=cost[i];
                cost[i]=tmp;
                pq.push({cost[i],i});
                co+=cost[i];
            }
        }
    }
    
    cout<<co;
}