#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;

class edge{
    public :
        ull st,en,w;
        edge(){
            st=-1;
            en=-1;
            w=0;
        }
        edge(ull x,ull y,ull c){
            st=x;
            en=y;
            w=c;
        }
        edge(const edge &X){
            st=X.st;
            en=X.en;
            w=X.w;
        }
        bool operator <(const edge &other)const{
            return w<other.w;
        }
        bool operator >(const edge &other)const{
            return w>other.w;
        }
};

ull find(ull st,vector<ull> & parent){
    if(parent[st]==-1)return st;
    return parent[st]=find(parent[st],parent);
}

void unionSet(ull st,ull en,vector<ull> & parent, vector<ull> & S){
    ull st_root=find(st,parent);
    ull en_root=find(en,parent);
    if(S[st_root]<S[en_root]){
        parent[st_root]=en_root;
        S[st_root]+=S[en_root];
    }
    else {
        parent[en_root]=st_root;
        S[en_root]+=S[st_root];
    }
}

ull n,co;


main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vector<ull>v;
    vector<edge>E;
    vector<ull>parent(n,-1);
    vector<ull>S(n,1);
    for(ull i=0;i<n;i++){
        ull a;cin>>a;
        v.push_back(a);
    }
    for(ull i=0;i<n;i++){
        for(ull j=0;j<n;j++){
            if(i!=j)E.push_back({i,j,v[i]^v[j]});
        }
    }
    sort(E.begin(),E.end(),greater<edge>());
    for(auto e:E){
        ull s1=find(e.st,parent);
        ull s2=find(e.en,parent);
        if(s1!=s2){
            unionSet(s1,s2,parent,S);
            co+=e.w;
        }
    }
    cout<<co;
}