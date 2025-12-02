#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int d,h,w;
    cin>>d>>h>>w;
    vector<vector<vector<int>>>qs(d+1,vector<vector<int>>(h+1,vector<int>(w+1,0)));
    vector<vector<vector<int>>>arr(d+1,vector<vector<int>>(h+1,vector<int>(w+1,0)));
    for(int i=1;i<=d;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++)cin>>arr[i][j][k];
        }
    }

    for(int i=1;i<=d;i++){
        for(int j=1;j<=h;j++){
            qs[i][j][0]=arr[i][j][0]+
                        qs[i-1][j][0]+
                        qs[i][j-1][0]-
                        qs[i-1][j-1][0];
        }
    }
    for(int j=1;j<=h;j++){
        for(int k=1;k<=w;k++){
            qs[0][j][k]=arr[0][j][k]+
                        qs[0][j-1][k]+
                        qs[0][j][k-1]-
                        qs[0][j-1][k-1];
        }
    }
    for(int k=1;k<=w;k++){
        for(int i=1;i<=d;i++){
            qs[i][0][k]=arr[i][0][k]+
                        qs[i-1][0][k]+
                        qs[i][0][k-1]-
                        qs[i-1][0][k-1];
        }
    }

    for(int i=1;i<=d;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++){
                qs[i][j][k]=arr[i][j][k]+
                            qs[i-1][j][k]+  
                            qs[i][j-1][k]+
                            qs[i][j][k-1]-

                            qs[i-1][j-1][k]-
                            qs[i][j-1][k-1]-
                            qs[i-1][j][k-1]+
                            
                            qs[i-1][j-1][k-1];
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int d1,h1,w1,d2,h2,w2;
        cin>>d1>>h1>>w1>>d2>>h2>>w2;
        int ans=qs[d2][h2][w2]-
                qs[d1-1][h2][w2]-
                qs[d2][h1-1][w2]-
                qs[d2][h2][w1-1]+

                qs[d1-1][h1-1][w2]+
                qs[d2][h1-1][w1-1]+
                qs[d1-1][h2][w1-1]-

                qs[d1-1][h1-1][w1-1];
        cout<<ans<<'\n';
    }
}