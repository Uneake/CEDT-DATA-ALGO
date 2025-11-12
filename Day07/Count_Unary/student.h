#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  //you may write additional code here
  if(ptr->left==nullptr&&ptr->right==nullptr)return 0;
  if(ptr->left==nullptr)return 1 + process(ptr->right);
  if(ptr->right==nullptr)return 1 + process(ptr->left);
  return process(ptr->left)+process(ptr->right);
  return 0;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
  return 0;
}

#endif
