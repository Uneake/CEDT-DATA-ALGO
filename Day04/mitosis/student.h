#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{   
    if (mSize+b-a+1 > mCap) {
        size_t s = (mSize+b-a+1 > 2 * mCap) ? mSize+b-a+1 : 2 * mCap;
        expand(s);
    }
    size_t j=0,snew=mSize+b-a+1,sold=mSize,co=0;
    for(size_t i=snew-1; i>=mSize-b;i--){
        size_t tmp=(snew-1)-i;
        mData[i]=mData[sold-j-1];
        if(tmp<a)j++;
        else if(tmp>=a)co++;
        if(co==2){
            co=0;
            j++;
        }
    }
    mSize+=b-a+1;
}

#endif