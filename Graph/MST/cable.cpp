#include <bits/stdc++.h>
using namespace std;

int n,co;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vector<vector<int>>G(n,vector<int>(n,0));
    vector<int>cost(n,INT_MAX);
    vector<bool>visit(n,false);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int w;cin>>w;
            G[i][j]=w;
            G[j][i]=w;
        }
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
            if(G[u][i]<cost[i]&&!visit[i]){
                if(cost[i]!=INT_MAX)co-=cost[i];
                cost[i]=G[u][i];
                pq.push({cost[i],i});
                co+=cost[i];
            }
        }
    }
    //for(auto x:cost)cout<<x<<' ';
    cout<<co;
}