#include <bits/stdc++.h>
using namespace std;

int n,a,co;
queue<int>q;
string ans;
main(){
    cin>>n>>a;
    q.push(a);
    while(!q.empty()){
        auto k=q.front();
        q.pop();
        co++;
        ans+=to_string(k)+' ';
        if(k*2+1<n)q.push(k*2+1);
        if(k*2+2<n)q.push(k*2+2);
    }
    cout<<co<<'\n'<<ans;
}