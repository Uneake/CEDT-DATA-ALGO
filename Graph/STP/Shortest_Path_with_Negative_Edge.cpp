#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,e,s;
    cin>>n>>e>>s;
    vector<pair<pii,int>>E;
    vector<int>DP(n,INT_MAX);
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        E.push_back({{a,b},c});
    }
    DP[s]=0;
    for(int i=0;i<n-1;i++){
        for(auto [p,w]:E){
            auto [u,v]=p;
            if(DP[v]>(DP[u]==INT_MAX ? INT_MAX : DP[u]+w))DP[v]=DP[u]+w;
        }
    }
    bool negative_cycle=false;
    for(auto [p,w]:E){
        auto [u,v]=p;
        if(DP[v]>(DP[u]==INT_MAX ? INT_MAX : DP[u]+w)){
            negative_cycle=true;
            break;
        }
    }
    if(negative_cycle)cout<< -1;
    else {
        for(auto w:DP)cout<<w<<' ';
    }
}