#include <bits/stdc++.h>
using namespace std;

int n,k;
void recur(int n,int k,int i,string ans){

    if(ans.size()==n){
        int co=0,mx=-1;
        bool check=false;
        for(int j=0;j<n;j++){
            if(!check&&ans[j]=='1'){
                co++;
                check=true;
            }
            else if(check&&ans[j]=='1')co++;
            else if(ans[j]=='0'){
                check=false;
                mx = max(co,mx);
                co=0;
            }
        }
        mx = max(mx,co);
        if(mx>=k)cout<<ans<<'\n';
        return;
    }

    recur(n,k,i+1,ans+'0');
    recur(n,k,i+1,ans+'1');
}

main(){
    cin>>n>>k;
    recur(n,k,0,"");
}
