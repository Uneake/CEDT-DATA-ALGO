#include <bits/stdc++.h>
using namespace std;

main(){
    int n,m,t;
    vector<int>v;
    cin>>n>>m;
    while(n--){
        cin>>t;
        v.push_back(t);
    }
    while(m--){
        cin>>t;
        int co=0,i=0;
        while(v[i]!=t){
            if(v[i]>t)co++;
            i++;
        }
        cout<<co<<'\n';
    }
    
}