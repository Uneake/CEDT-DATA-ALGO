#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::parity_score(int d) {
    int parity_score=0;
    parity_score_helper(mRoot,d,parity_score);
    return (parity_score<0 ? -parity_score : parity_score);
}

template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::parity_score_helper(node *current_node, int depth, int &parity_score){
    // You may write your code here
    if(depth<0)return;
    if(current_node)parity_score+= ( (current_node->data.first % 2) ? 1 : -1 );
    else return;
    parity_score_helper(current_node->left,depth-1,parity_score);
    parity_score_helper(current_node->right,depth-1,parity_score);
}


#endif
