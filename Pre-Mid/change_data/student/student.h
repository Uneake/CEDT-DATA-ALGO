#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>>tmp;
    while(!a.empty()){
        auto p=a.top();
        a.pop();
        for(auto &q:p){
            for(int i=0;i<q.size();i++){
                auto tmp2=q.front();
                q.pop();
                if(tmp2==from)tmp2=to;;
                q.push(tmp2);
            }
        }
        tmp.push(p);
    }
    while(!tmp.empty()){
        a.push(tmp.top());
        tmp.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &p:a){
        auto & pq=p.second.first;
        auto & val=p.second.second;
        if(val==from)val=to;
        std::vector<int>tmp;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            if(t==from)t=to;
            tmp.push_back(t);
        }
        for(auto & k:tmp)pq.push(k);
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::vector<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>>v;
    auto it=a.begin();
    while(it!=a.end()){
        auto t = *it;
        it = a.erase(it);
        auto & l = t.first;
        auto & m = t.second;
        for(auto & val:l)if(val==from)val=to;
        for(auto &p:m){
            auto val=p.second;
            if(val.first==from)val.first=to;
            if(p.first==from){
                m.erase(from);
                m[to]=val;
            }
            else m[p.first]=val;
        }
        v.push_back({l,m});
    }
    for(auto t:v)a.insert(t);
}

#endif
