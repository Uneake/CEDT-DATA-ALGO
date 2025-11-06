#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  T tmp=mData[(mFront+pos)%mCap];
  for(size_t i=(mFront+pos)%mCap;i!=(mFront+mSize-1)%mCap;i=(i+1)%mCap){
    mData[i]=mData[(i+1)%mCap];
  }
  mData[(mFront+mSize-1)%mCap]=tmp;
}

#endif
