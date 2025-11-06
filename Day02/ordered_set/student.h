#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    s.insert(A.begin(),A.end());
    v=A;
    for(auto x:B){
        if(s.find(x)==s.end())v.push_back(x);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    s.insert(B.begin(),B.end());
    for(auto x:A){
        if(s.find(x)!=s.end())v.push_back(x);
    }
    return v;
}
