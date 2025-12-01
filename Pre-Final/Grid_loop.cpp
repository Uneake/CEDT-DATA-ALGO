#include <bits/stdc++.h>
using namespace std;

int r,c,ans,mx=0;
unordered_map<int,pair<char,char>>m;
pair<int,int> pos(char chr, int r,int c){
    if(chr=='l')return {r,c-1};
    if(chr=='r')return {r,c+1};
    if(chr=='u')return {r-1,c};
    if(chr=='d')return {r+1,c};
}
char op(char c){
    if(c=='l')return 'r';
    if(c=='r')return 'l';
    if(c=='u')return 'd';
    if(c=='d')return 'u';
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    m[1]={'l','r'};
    m[2]={'u','d'};
    m[3]={'u','r'};
    m[4]={'r','d'};
    m[5]={'l','d'};
    m[6]={'u','l'};
    cin>>r>>c;
    vector<vector<pair<char,char>>>v(r,vector<pair<char,char>>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int t;
            cin>>t;
            v[i][j]=m[t];
        }
    }
    vector<vector<bool>>visit(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(visit[i][j])continue;
            stack<pair<pair<int,int>,pair<int,int>>>st;
            st.push({{i,j},{-1,-1}});
            int co=0;
            bool cycle=false;
            while(!st.empty()){
                auto [now,parent]=st.top();
                auto [row,col]=now;
                auto letter=v[row][col];
                st.pop();
                visit[row][col]=true;
                co++;
                auto next1=pos(letter.first,row,col);
                auto next2=pos(letter.second,row,col);
                if(next1.first>=0&&next1.second>=0&&next1.first<r&&next1.second<c&&
                  (v[next1.first][next1.second].first==op(letter.first)||
                   v[next1.first][next1.second].second==op(letter.first))){
                    if(!visit[next1.first][next1.second]){
                        st.push({next1,now});
                    }
                    else if(next1!=parent){
                        cycle=true;
                        break;
                    }
                }
                if(next2.first>=0&&next2.second>=0&&next2.first<r&&next2.second<c&&
                  (v[next2.first][next2.second].first==op(letter.second)||
                   v[next2.first][next2.second].second==op(letter.second))){
                    if(!visit[next2.first][next2.second]){
                        st.push({next2,now});
                    }
                    else if(next2!=parent){
                        cycle=true;
                        break;
                    }
                }
            }
            if(cycle){
                ans++;
                mx=max(mx,co);
            }
        }
    }
    cout<<ans<<' '<<mx;
}