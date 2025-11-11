#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto &l:ls){
    if(l.mSize==0)continue;
    mSize+=l.mSize;
    l.mSize = 0;
    auto sub_head = (l.mHeader)->next;
    auto sub_tail = (l.mHeader)->prev;
    auto main_head = mHeader->next;
    auto main_tail = mHeader->prev;
    
    //cut l.mHeader
    (l.mHeader)->next = l.mHeader;
    (l.mHeader)->prev = l.mHeader;

    //link mHeader
    mHeader->prev = sub_tail;
    sub_tail->next = mHeader;

    //link sub_head
    sub_head->prev = main_tail;
    main_tail->next = sub_head;
    
  }
}

#endif
