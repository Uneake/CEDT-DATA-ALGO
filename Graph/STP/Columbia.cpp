#include <bits/stdc++.h>
using namespace std;
using pipii=pair<int,pair<int,int>>;

int row,col;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>row>>col;
    vector<vector<int>>v(row,vector<int>(col));
    vector<vector<bool>>visit(row,vector<bool>(col,false));
    vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)cin>>v[i][j];
    }
    priority_queue<pipii,vector<pipii>,greater<pipii>>pq;
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
        auto [w,p]=pq.top();
        auto [r,c]=p;
        pq.pop();
        visit[r][c]=true;
        if(r+1<row&&dist[r+1][c]>v[r+1][c]+w&&!visit[r+1][c]){
            dist[r+1][c]=v[r+1][c]+w;
            pq.push({dist[r+1][c],{r+1,c}});
        }
        if(r-1>=0&&dist[r-1][c]>v[r-1][c]+w&&!visit[r-1][c]){
            dist[r-1][c]=v[r-1][c]+w;
            pq.push({dist[r-1][c],{r-1,c}});
        }
        if(c+1<col&&dist[r][c+1]>v[r][c+1]+w&&!visit[r][c+1]){
            dist[r][c+1]=v[r][c+1]+w;
            pq.push({dist[r][c+1],{r,c+1}});
        }
        if(c-1>=0&&dist[r][c-1]>v[r][c-1]+w&&!visit[r][c-1]){
            dist[r][c-1]=v[r][c-1]+w;
            pq.push({dist[r][c-1],{r,c-1}});
        }
    }
    for(auto i:dist){
        for(auto j:i)cout<<j<<' ';
        cout<<'\n';
    }
}