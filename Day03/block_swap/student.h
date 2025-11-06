#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  using std::swap;
  if(a>b)swap(a,b);
  if(a>=begin()&&a<end()&&a+m-1<end()&&
     b>=begin()&&b<end()&&b+m-1<end()&&
     m>0&&a+m-1<b){
      for(size_t i=0;i<m;i++)swap(*(a+i),*(b+i));
      return true;
  }
  else return false;
}

#endif
