#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
using namespace std;

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  size_t l=data.size();
  sort(data.begin(),data.end());
  size_t j=0,k=0;
  T* arr = new T[mSize+l];
  for(size_t i=0;i<mSize+l;i++) {
    if(j<l&&k==data[j].first){
      arr[i] = data[j].second;
      j++;
    }
    else arr[i] = mData[k++];
  }
  delete [] mData;
  mData=arr;
  mSize+=l;
  mCap=mSize;
}

#endif