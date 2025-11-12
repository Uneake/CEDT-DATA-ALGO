// Your code here
int dfs(node* n,int & imb_max,KeyT & key){
    if(!n)return -1;
    int right_height = dfs(n->right,imb_max,key);
    int left_height = dfs(n->left,imb_max,key);
    int delta = right_height-left_height;

    if(delta<0)delta = -delta;
    if(imb_max<delta){
        imb_max = delta;
        key = (n->data).first;
    }
    else if(imb_max==delta&&((n->data).first<key)){
        imb_max = delta;
        key = (n->data).first;
    }

    return 1+((right_height>left_height) ? right_height : left_height);
}

KeyT getValueOfMostImbalanceNode() {
    int imb_max=-1;
    KeyT key=(mRoot->data).first;
    dfs(mRoot,imb_max,key);
    return key;
    // Your code here
}
