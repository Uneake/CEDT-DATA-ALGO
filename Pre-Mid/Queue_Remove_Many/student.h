#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::vector<bool> remove(mSize, false);
    for (auto p : pos) {
        if (p < mSize) remove[p] = true;
    }
    size_t j = 0;
    for (size_t i = 0; i < mSize; i++) {
        if (!remove[i]) {
            mData[(mFront + j) % mCap] = mData[(mFront + i) % mCap];
            j++;
        }
    }
    mSize = j;
}

#endif
