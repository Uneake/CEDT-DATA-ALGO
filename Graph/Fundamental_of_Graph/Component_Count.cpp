#include <bits/stdc++.h>
using namespace std;

int v,e,co;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>v>>e;
    vector<vector<int>>V(v+1);
    vector<bool>visit(v+1);
    while (e--){
        int st,en;
        cin>>st>>en;
        V[st].push_back(en);
        V[en].push_back(st);
    }
    queue<int>q;
    for(int i=1;i<=v;i++){
        if(visit[i])continue;
        co++;
        q.push(i);
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            if(visit[tmp])continue;
            visit[tmp]=true;
            for(auto x:V[tmp]){
                if(!visit[x])q.push(x);
            }
        }
    }    
    cout<<co;
}