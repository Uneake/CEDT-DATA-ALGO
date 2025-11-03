#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n,m,k;
    cin>>n>>m>>k;
    while(n--){
        int t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    while(m--){
        int t;
        cin>>t;
        cout<< upper_bound(v.begin(),v.end(),t+k)-lower_bound(v.begin(),v.end(),t-k) <<' ';
    }
    return 0;
}