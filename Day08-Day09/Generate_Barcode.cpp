#include <bits/stdc++.h>
using namespace std;

map<int,bool>visited;
vector<int> v;
int n,m;

void recur(int n,int m,vector<int>& change,string ans){
    if(change.size()>=n){
        for(auto x:change){
            ans[x]='1';
        }
        cout<<ans<<'\n';
        
        return;
    }
    for(int j=m-1;j>=0;j--){
        if(!visited[j]){
            if(!change.empty()&&(*(change.end()-1))<j)continue;
            visited[j]=true;
            change.push_back(j);
            recur(n,m,change,ans);
            visited[j]=false;
            change.pop_back();
        }
    }
}

main(){
    cin>>n>>m;
    string tmp="";
    for(int i=0;i<m;i++)tmp+='0';
    recur(n,m,v,tmp);
}
