#include <bits/stdc++.h>
using namespace std;

void permute(int n,string & all,string & tmp,set<string> & ans,vector<bool> & visit){
    int l=all.length();
    if(n>=l){
        ans.insert(tmp);
        return;
    }
    for(int i=0;i<l;i++){
        if(visit[i])continue;
        if(i>0&&all[i]==all[i-1]&&!visit[i-1])continue;
        visit[i]=true;
        tmp+=all[i];
        permute(n+1,all,tmp,ans,visit);
        tmp.pop_back();
        visit[i]=false;
    }
}

set<string>ans;
string s;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    string tmp="";
    vector<bool>visit(s.length(),false);
    sort(s.begin(),s.end());
    permute(0,s,tmp,ans,visit);
    cout<<ans.size()<<'\n';
    for(auto st:ans)cout<<st<<'\n';
}