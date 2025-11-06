#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  if(aux){
    mFront = (mFront-mSize+1+mCap)%mCap;
    aux=0;
  }
  else {
    mFront = (mFront+mSize-1)%mCap;
    aux=1;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  int c=1;
  if(aux)c=-1;
  return mData[(mFront + (mSize - 1)*c+mCap) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  int c=1;
  if(aux)c=-1;
  ensureCapacity(mSize + 1);
  mData[(mFront + c*mSize+mCap) % mCap] = element;
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  int c=1;
  if(aux)c=-1;
  mFront = (mFront + c + mCap) % mCap;
  mSize--;
}

#endif