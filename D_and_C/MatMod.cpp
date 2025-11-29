#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v(2,vector<int>(2,0));
vector<vector<int>>ans(2,vector<int>(2,0));
int n,k;

vector<vector<int>> mat_mul(vector<vector<int>> & v1,vector<vector<int>> & v2,int k){
    auto tmp=v1;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tmp[i][j]=0;
            for(int o=0;o<2;o++){
                tmp[i][j]+=((v1[i][o]%k)*(v2[o][j]%k))%k;
                tmp[i][j]%=k;
            }
        }
    }
    return tmp;
}

vector<vector<int>> mat_mod(vector<vector<int>> & v,int n,int k){
    //cout<<n<<endl;
    if(n==1)return v;
    if(n==0)return {{1,0},
                    {0,1}};
    auto tmp = mat_mod(v,n/2,k);
    auto ans = mat_mul(tmp,tmp,k);
    if(n%2)return mat_mul(ans,v,k);
    else return ans;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)cin>>v[i][j];
    }
    ans = mat_mod(v,n,k);
    for(auto vec:ans){
        for(auto val:vec)cout<<val<<' ';
    }
}