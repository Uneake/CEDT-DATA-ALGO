#include <bits/stdc++.h>
using namespace std;

int R,C;

void walk(int r, int c,const int & end_row, const int & end_col,
          const vector<vector<int>> & v, map<pair<int,int>,bool> & visited, string ans){
    if(r<=0||c<=0||r>end_row||c>end_col||v[r-1][c-1]==1||visited[{r,c}])return;
    if(r==end_row&&c==end_col){
        cout<<ans<<'\n';
        return;
    }
    visited[{r,c}]=true;
    walk(r,c+1,end_row,end_col,v, visited,ans+'A');
    walk(r+1,c,end_row,end_col,v, visited,ans+'B');
    walk(r-1,c,end_row,end_col,v, visited,ans+'C');
    visited[{r,c}]=false;
}

main(){
    cin>>R>>C;
    vector<vector<int>> v(R,vector<int>(C));
    map<pair<int,int>,bool>visited;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cin>>v[i][j];
    }
    walk(1,1,R,C,v,visited,"");
    cout<<"DONE";
}