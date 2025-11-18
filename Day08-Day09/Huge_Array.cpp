#include <bits/stdc++.h>
using namespace std;

main(){
    map<int,int>multiple;
    map<int,int>arr;
    int n,q,all_c=0;
    cin>>n>>q;
    while(n--){
        int x,c;
        cin>>x>>c;
        multiple[x]+=c;
        all_c+=c;
    }
    int i=0;
    for(auto &p:multiple){
        arr[i+p.second]=p.first;
        i+=p.second;
    }
    while(q--){
        int t;
        cin>>t;
        cout<< (*arr.lower_bound(t)).second<<'\n';
    }
    
}