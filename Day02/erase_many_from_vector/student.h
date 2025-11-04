#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  int l=pos.size();
  for(int i=0;i<l;i++){
    erase(begin()+pos[i]-i);
  }
}

#endif
