#include <bits/stdc++.h>
using namespace std;

map<string,int>name;
int n,k,co,mn;
priority_queue<int>pq;
main(){
    cin>>n>>k;
    while(n--){
        string t;cin>>t;
        name[t]++;
    }
    for(auto p:name)pq.push(p.second);
    while(!pq.empty()){
        mn=pq.top();
        pq.pop();
        co++;
        if(co==k)break;
    }
    cout<<mn;
}