#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  size_t t=last-first;
  size_t pos=position-begin();
  ensureCapacity(mSize+t);
  for(size_t i=mSize+t-1;i>pos+t-1;i--){
    mData[i]=mData[i-t];
  }
  for(size_t i = pos;i<pos+t;i++){
    mData[i]=*(first+i-pos);    
  }
  mSize+=t;
}

#endif
