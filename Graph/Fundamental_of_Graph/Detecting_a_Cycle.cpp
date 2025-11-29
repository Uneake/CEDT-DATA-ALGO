#include <bits/stdc++.h>
using namespace std;

int T;

int find_head(int n,map<int,int> & m){
    if(m.find(n)==m.end()){
        m[n]=n;
        return n;
    }
    if(m[n]==n)return n;
    m[n]=find_head(m[n],m);
    return m[n];
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--){
        int n,e;
        cin>>n>>e;
        map<int,int>head;
        bool cycle=false;
        while (e--){
            int st,en;cin>>st>>en;
            int st_head=find_head(st,head);
            int en_head=find_head(en,head);
            if(st_head==en_head)cycle=true;
            else head[st_head]=en_head;
        }
        if(cycle)cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    
}