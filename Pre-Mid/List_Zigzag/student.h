
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    /*

        “In war, then, let your great object be victory, not lengthy campaigns.”
        ― Sun Tzu, The Art of War 

    */
    node* head=mHeader->next;
    node* tail=ls.mHeader->next;
    node* before=ls.mHeader->prev;
    while(tail!=mHeader&&tail!=ls.mHeader){
        node* new_tail=head->next;
        head->next=tail;
        tail->prev=head;
        head=tail;
        tail=new_tail;
    }

    ls.mHeader->next=ls.mHeader;
    ls.mHeader->prev=ls.mHeader;

    if(tail==mHeader){
        before->next=mHeader;
        mHeader->prev=before;
    }

    mSize+=ls.mSize;
    ls.mSize=0;
}

#endif
