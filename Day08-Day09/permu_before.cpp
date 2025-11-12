#include <bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,int>after;
int n,m,a,b;

void recur(int n,int i,string ans, map<int,int>&  after){
    if(i==n){
        cout<<ans<<'\n';
        return;
    }
    for(int j=0;j<n;j++){
        if(!visited[j]){
            if(after.find(j)!=after.end() && (!visited[after[j]]))continue;
            visited[j]=true;
            recur(n,i+1,ans+to_string(j)+' ',after);
            visited[j]=false;
        }
    }
}

main(){
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        after[b]=a;
    }
    recur(n,0,"",after);
}
