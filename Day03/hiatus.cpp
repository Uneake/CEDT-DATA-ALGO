#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
set<pair<int,int>>s;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    while(n--){
        cin>>a>>b;
        s.insert({a,b});
    }
    while(m--){
        cin>>a>>b;
        if(a<s.begin()->first)cout<<-1<<' '<<-1<<' ';
        else if(a==s.begin()->first&&b<s.begin()->second)cout<<-1<<' '<<-1<<' ';
        else {
            auto it1=s.find({a,b}),it2=s.lower_bound({a,b});
            if(it1!=s.end())cout<<0<<' '<<0<<' ';
            else{
                    it2--;
                    cout<<it2->first<<' '<<it2->second<<' ';
            }
        }
    }
}