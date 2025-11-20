#include <bits/stdc++.h>
using namespace std;

int N,D,T,Z,t,z,co;
map<int,priority_queue<int,vector<int>,greater<int>>>item;
priority_queue<int,vector<int>,greater<int>> tmp;
bool cant_go=false;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>D>>T>>Z;
    while(D--){
        cin>>t>>z;
        if(item.find(z)==item.end())item[z]=tmp;
        item[z].push(t);
    }
    while(N--){
        int q;cin>>q;
        while(q--){
            cin>>z;
            if(!item[z].empty()){
                T-=item[z].top();
                item[z].pop();
                //cout<<T<<endl;
            }
            else if(item[z].empty())cant_go=true;
            if(T<0)cant_go=true;
            
        }
        if(!cant_go)co++;   
    }
    cout<<co;
}