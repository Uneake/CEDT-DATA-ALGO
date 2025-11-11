void replace(const T& x, list<T>& y) {
  //write your code here
  node * it=mHeader->next;
  while(it!=end().ptr){
    if(it->data==x){

      node* next=it->next;
      if(!y.empty()){
        node* head = new node;
        head->data = y.begin().ptr->data;
        node* tail=head;
        for(node* i=y.begin().ptr->next;i!=y.end().ptr;i=i->next){
          node* tmp = new node;
          tmp->data = i->data;
          tmp->prev=tail;
          tail->next=tmp;
          tail=tail->next;
        }
        
        head->prev = it->prev;
        tail->next = it->next;
        it->prev->next = head;
        it->next->prev = tail;
        mSize+=y.mSize-1;
      }
      else {
        it->prev->next = next;
        next->prev = it->prev;
        mSize--;
      }
      delete it;
      it = next;
      
    }
    else it=it->next;
  }
}
