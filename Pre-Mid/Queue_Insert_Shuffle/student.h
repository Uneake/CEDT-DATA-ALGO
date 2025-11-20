#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	size_t sz1=mSize;
	size_t it=0;
	for(int i=0;i<sz1;i++){
		auto c=front();
		pop();
		if(i>=pos){
			if(it<items.size())push(items[it++]);
		}
		push(c);
	}
	while(it<items.size())push(items[it++]);
}

#endif
