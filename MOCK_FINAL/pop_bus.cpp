#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

bool isnum(char c){
    return (c>='0'&&c<='9');
}

int manh_zero(pair<int,int> p){
    return p.first+p.second;
}

int row,col;
map<char,pair<int,int>>st,en;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>row>>col;
    vector<vector<char>>v(row,vector<char>(col));
    vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
    vector<vector<bool>>visit(row,vector<bool>(col,false));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>v[i][j];
            if(isnum(v[i][j])){
                if(st.find(v[i][j])==st.end())st[v[i][j]]={i,j};
                else {
                    if(manh_zero(st[v[i][j]])>manh_zero({i,j})){
                        en[v[i][j]]=st[v[i][j]];
                        st[v[i][j]]={i,j};
                    }
                    else en[v[i][j]]={i,j};
                }
            }
            if(v[i][j]=='X')visit[i][j]=true;
        }
    }

    queue<pair<int,pii>>q;
    q.push({0,{0,0}});
    while(!q.empty()){
        auto [w,p]=q.front();
        auto [r,c]=p;
        auto chr=v[r][c];
        q.pop();
        visit[r][c]=true;
        //cout<<endl;
        // for(auto x:visit){
        //     for(auto y:x)cout<<y<<' ';
        //     cout<<endl;
        // }
        if(c-1>=0&&dist[r][c-1]>w+1&&!visit[r][c-1]){
            dist[r][c-1]=w+1;
            q.push({w+1,{r,c-1}});
        }
        if(c+1<col&&dist[r][c+1]>w+1&&!visit[r][c+1]){
            dist[r][c+1]=w+1;
            q.push({w+1,{r,c+1}});
        }
        if(r+1<row&&dist[r+1][c]>w+1&&!visit[r+1][c]){
            dist[r+1][c]=w+1;
            q.push({w+1,{r+1,c}});
        }
        if(isnum(chr)){
            if(st[chr]==p&&dist[en[chr].first][en[chr].second]>w&&!visit[en[chr].first][en[chr].second]){
                //cout<<"DEBUG\n";
                dist[en[chr].first][en[chr].second]=w;
                q.push({w,en[chr]});
            }
        }
    }
    cout<<dist[row-1][col-1];
}