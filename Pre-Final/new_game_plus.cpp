#include <bits/stdc++.h>
using namespace std;
const int M=1e8+7;

int A(int r,int c,int R,int C,vector<vector<int>> & v, vector<vector<int>> & ans){
    //cout<<r<<' '<<c<<endl;
    if(r<0||c<0||r>=R||c>=C)return 0;   
    if(v[r][c]==1)return 0;
    if(ans[r][c]!=-1)return ans[r][c]%M;
    int mul=1;
    ans[r][c]=0;
    int k1=1,k2=1,k3=1;
    for(int i=1;i<=c;i++){
        if(r-i>=0&&c-i>=0&&v[r-i][c-i]==1)k1=0;
        if(c-i>=0&&v[r][c-i]==1)k2=0;
        if(r+i<R&&c-i>=0&&v[r+i][c-i]==1)k3=0;
        if(k1==1)ans[r][c]=(ans[r][c]%M+mul*(A(r-i,c-i,R,C,v,ans)%M))%M;
        if(k2==1)ans[r][c]=(ans[r][c]%M+mul*(A(r,c-i,R,C,v,ans)%M))%M;
        if(k3==1)ans[r][c]=(ans[r][c]%M+mul*(A(r+i,c-i,R,C,v,ans)%M))%M;
        mul*=-1;
        if(ans[r][c]<0)ans[r][c]+=M;
        ans[r][c]%M;
    }
    return ans[r][c]%M;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r,c; cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c,0));
    vector<vector<int>>ans(r,vector<int>(c,-1));
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
            if(j==0)ans[i][j]=1;
        }
    }
    for(int i=0;i<r;i++){
        sum+=A(i,c-1,r,c,v,ans)%M;
        sum%=M;
    }
    cout<<sum;
}