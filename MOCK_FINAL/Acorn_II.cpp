#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int d,h,w;
    cin>>d>>h>>w;
    vector<vector<vector<int>>>arr(d+1,vector<vector<int>>(h+1,vector<int>(w+1,0)));
    for(int i=1;i<=d;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++){
              cin>>arr[i][j][k];
              arr[i][j][k]=arr[i][j][k]+
                            arr[i-1][j][k]+  
                            arr[i][j-1][k]+
                            arr[i][j][k-1]-

                            arr[i-1][j-1][k]-
                            arr[i][j-1][k-1]-
                            arr[i-1][j][k-1]+
                            
                            arr[i-1][j-1][k-1];
            }
        }
    }

    int q;cin>>q;
    while(q--){
        int d1,h1,w1,d2,h2,w2;
        cin>>d1>>h1>>w1>>d2>>h2>>w2;
        int ans=arr[d2][h2][w2]-
                arr[d1-1][h2][w2]-
                arr[d2][h1-1][w2]-
                arr[d2][h2][w1-1]+

                arr[d1-1][h1-1][w2]+
                arr[d2][h1-1][w1-1]+
                arr[d1-1][h2][w1-1]-

                arr[d1-1][h1-1][w1-1];
        cout<<ans<<'\n';
    }
}