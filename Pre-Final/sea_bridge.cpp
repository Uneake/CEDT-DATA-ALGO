#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int mn=INT_MAX;
    int r,c;cin>>r>>c;
    pair<int,int>st,en;
    vector<vector<int>>v(r,vector<int>(c));
    vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
    vector<vector<bool>>visit(r,vector<bool>(c,false));
    priority_queue<pair<int,pii>,vector<pair<int,pii>>, greater<pair<int,pii>> >pq;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
            if(v[i][j]==1){
                pq.push({1,{i,j}});
                dist[i][j]=1;
            }
            if(v[i][j]==3)visit[i][j]=true;
        }
    }
    while(!pq.empty()){
        auto [w,p]=pq.top();
        auto [i,j]=p;
        pq.pop();
        visit[i][j]=true;
        if(v[i][j]==2)mn = min(mn,dist[i][j]);
        if(i+1<r&&dist[i+1][j]>w+1&&!visit[i+1][j]){
            dist[i+1][j]=w+1;
            pq.push({w+1,{i+1,j}});
        }
        if(i-1>=0&&dist[i-1][j]>w+1&&!visit[i-1][j]){
            dist[i-1][j]=dist[i][j]+1;
            pq.push({w+1,{i-1,j}});
        }
        if(j+1<c&&dist[i][j+1]>w+1&&!visit[i][j+1]){
            dist[i][j+1]=dist[i][j]+1;
            pq.push({w+1,{i,j+1}});
        }
        if(j-1>=0&&dist[i][j-1]>w+1&&!visit[i][j-1]){
            dist[i][j-1]=dist[i][j]+1;
            pq.push({w+1,{i,j-1}});
        }
    }
    cout<<mn;
}