#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> day;
vector<vector<int>>student;

void combi(int i,int n,int co,int &mn){
    if(co==day.size()){
        //cout<<n<<endl;
        mn = min(mn,n);
        return;
    }
    if(i>=student.size()||n>=mn)return;
    int tmp=0;
    for(auto val:student[i]){
        if(day[val]<=0)tmp++;
        day[val]++;
    }
    combi(i+1,n+1,co+tmp,mn);
    for(auto val:student[i])day[val]--;
    combi(i+1,n,co,mn);

}
main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m;
    day.resize(n);
    student.resize(m);
    for(int i=0;i<m;i++){
        int t,s;
        cin>>s;
        while(s--){
            cin>>t;
            student[i].push_back(--t);
        }
    }
    
    int mn=m;
    combi(0,0,0,mn);
    cout<<mn;
}