#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right){
    if(a==0){
        v[top][left]=b;
        return;
    }
    int new_a=a-1;
    int new_bottom=1<<new_a;
    recur(v,new_a,b,top,new_bottom,left,right/2);
    recur(v,new_a,b-1,top,new_bottom,left+new_bottom,right);
    recur(v,new_a,b+1,top+new_bottom,bottom,left,right/2);
    recur(v,new_a,b,top+new_bottom,bottom,left+new_bottom,right);

}
int a,b;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    int bottom=1<<a;
    vector<vector<int>> H(bottom,vector<int>(bottom,0));
    recur(H ,a ,b ,0 ,bottom ,0 ,bottom);
    for(auto v:H){
        for(auto val:v)cout<<val<<' ';
        cout<<'\n';
    }
}   