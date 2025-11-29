#include <bits/stdc++.h>
using namespace std;

int n;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int a,mx=-1;
    map<int,int> ans;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            cin>>a;
            sum+=a;
        }
        mx=max(mx,sum);
        ans[sum]++;
    }
    for(int i=0;i<=mx;i++)cout<<ans[i]<<' ';
}