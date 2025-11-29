#include <bits/stdc++.h>
using namespace std;

int v,co,head;
map<int,int>from;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>v;
    vector<vector<int>>V(v+1);
    vector<bool>visit(v+1);
    for(int i=0;i<v;i++){
        int st,en;
        cin>>st>>en;
        V[st].push_back(en);
        V[en].push_back(st);
    }
    stack<pair<int,int>>stk;
    stk.push({0,0});
    bool ch=false;
    while(!stk.empty()){
        auto [tmp,parent]=stk.top();
        stk.pop();
        if(visit[tmp])continue;
        visit[tmp]=true;
        for(auto x:V[tmp]){
            if(visit[x]&&x!=parent){
                head=tmp;
                from[x]=tmp;
                break;
            }
            if(!visit[x]){
                stk.push({x,tmp});
                from[x]=tmp;
            }
        }
    }
    int cur=head;
    co++;
    cur=from[cur];
    while(cur!=head){
        co++;
        cur=from[cur];
    }

    cout<<co;
}