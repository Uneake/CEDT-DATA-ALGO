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
    stack<pair<int,int>>stk;
    for(int i=0;i<v;i++){
        if(visit[i])continue;
        stk.push({i,i});
        bool ch=false;
        while(!stk.empty()){
            auto [tmp,parent]=stk.top();
            stk.pop();
            if(visit[tmp])continue;
            visit[tmp]=true;
            if(V[tmp].size()>2)ch=true;
            for(auto x:V[tmp]){
                if(visit[x]&&x!=parent)ch=true;
                if(!visit[x])stk.push({x,tmp});
            }
        }
        if(!ch)co++;
    }    
    cout<<co;
}