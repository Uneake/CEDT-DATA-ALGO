#include <bits/stdc++.h>
using namespace std;

list<int> l;
int n,k,v;

main(){
    cin>>n>>k>>v;
    while(n--){
        int t;cin>>t;
        l.push_back(t);
    }
    auto it=l.begin();
    advance(it,k);
    it = l.insert(it,v);
    int dis=3;
    while(dis>=3){
        auto st=it,en=it;
        while(st!=l.begin()&& *prev(st,1)==*it)st = prev(st,1);
        while(en!=l.end()&& *en==*it)en = next(en,1);
        dis = distance(st,en);
        if(dis>=3)it = l.erase(st,en);
        if(*it!=*prev(it,1))break;
        
    }
    for(auto x:l)cout<<x<<' ';
}