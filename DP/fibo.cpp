#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int prev=1,now=1;
    for(int i=3;i<=n;i++){
        int tmp=now;
        now+=prev;
        prev=tmp;
    }
    cout<<now;
}