#include <bits/stdc++.h>
using namespace std;

main(){
    set<int> s;
    int n;cin>>n;
    bool flag=0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        flag = flag||(t<1)||t>n;
        s.insert(t);
    }
    cout<< (n==s.size()&&!flag ? "YES" : "NO");
}