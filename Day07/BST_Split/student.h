#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node *cur = mRoot;
  node *leftTree = nullptr;   
  node *rightTree = nullptr;  
  node *leftTail = nullptr;   
  node *rightTail = nullptr;  

  while (cur) {
    if (mLess(cur->data.first, val)) {
      node *next = cur->right;
      if (leftTail) leftTail->right = cur;
      else leftTree = cur;
      cur->parent = leftTail;
      leftTail = cur;
      cur = next;
    } else {
      node *next = cur->left;
      if (rightTail) rightTail->left = cur;
      else rightTree = cur;
      cur->parent = rightTail;
      rightTail = cur;
      cur = next;
    }
  }

  if (leftTail) leftTail->right = nullptr;
  if (rightTail) rightTail->left = nullptr;

  mRoot = leftTree;
  result.mRoot = rightTree;

  return result;
}

#endif
