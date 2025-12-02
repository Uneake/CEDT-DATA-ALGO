#include <bits/stdc++.h>
using namespace std;

const int M=1e8+7;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int C=1,E=1,D=1,T=1;
    for(int i=2;i<=n;i++){
        int nC=(D%M+T%M)%M;
        int nE=(C+T)%M;
        int nD=E%M;
        int nT=C%M;

        C=nC;
        E=nE;
        D=nD;
        T=nT;
    }
    cout<<(C%M+(E%M+(D%M+T%M)%M)%M)%M;
}