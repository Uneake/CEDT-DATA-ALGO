#include <bits/stdc++.h>
using namespace std;

int n,m,start,a,x,p,s,now;
map<int,int> change;
vector<int> v;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>start;
    v.push_back(start);
    now = start;
    for(int i=0;i<n;i++){
        cin>>a>>s;
        change[a]=s;
    }
    for(int i=1;i<=100000;i++){
        auto it =change.find(i);
        if(it!=change.end()){
            now = it->second;
        }
        v.push_back(v[i-1]+now);
    }
    while(m--){
        cin>>p>>x;
        auto it1=lower_bound(v.begin(),v.end(),p+v[x])-v.begin(),it2=lower_bound(v.begin(),v.end(),p)-v.begin();
        cout<< (it2<=x ? it2 : it1) <<' ';
    }
}