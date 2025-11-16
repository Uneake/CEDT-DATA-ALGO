#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if(n==nullptr)return 0;
    int l=my_recur(n->left,aux);
    int r=my_recur(n->right,aux);
    aux = std::max(l+r,aux);
    return 1+std::max(l,r);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	if(empty())return -1;
    int mx=0;
    my_recur(mRoot,mx);
    return mx;
}

#endif
