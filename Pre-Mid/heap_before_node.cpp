#include <bits/stdc++.h>
using namespace std;

queue<int>q;
int n,m,co;
string ans;
main(){
    cin>>n>>m;
    q.push(0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==m)continue;
        ans+=to_string(t)+' ';
        co++;
        if(2*t+1<n)q.push(2*t+1);
        if(2*t+2<n)q.push(2*t+2);
    } 
    cout<<co<<'\n'<<ans;
}