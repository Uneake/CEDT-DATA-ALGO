#include <bits/stdc++.h>
using namespace std;

const int MOD=1e8+7;
int n;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int max_prev=7;
    int min_prev=5;
    for(int i=3;i<=n;i++){
        int tmp=max_prev;
        max_prev=(max_prev+(2*(min_prev%MOD))%MOD)%MOD;
        min_prev=(tmp%MOD+(min_prev%MOD))%MOD;
    }
    cout<<max_prev;
}