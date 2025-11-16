#include <bits/stdc++.h>
using namespace std;

map<int,int>finish;
int n,command,a,b,i;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        cin>>command;
        if(command==1){
            cin>>a>>b;
            auto it=finish.lower_bound(a);
            if(it!=finish.begin()){
                it--;
                if(it->second < a-1)it++;
            }
            while(it!=finish.end()&&b+1>=it->first){
                a=min(a,it->first);
                b=max(b,it->second);
                it=finish.erase(it);
            }
            finish[a]=b;
        }
        else {
            cout<<finish.size()<<'\n';
        }
    }
}