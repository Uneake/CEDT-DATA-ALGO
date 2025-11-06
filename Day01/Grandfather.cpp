#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> father;
main(){
    long long n,m;cin>>n>>m;
    while(n--){
        long long fath,son;cin>>fath>>son;
        father[son]=fath;
    }
    while(m--){
        long long s1,s2;cin>>s1>>s2;
        cout<< (s1!=s2 && father[father[s1]]==father[father[s2]] && father[father[s1]]!=0 ? "YES\n" : "NO\n");
    }
}