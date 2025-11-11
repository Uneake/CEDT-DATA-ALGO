void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if(mSize==0)return;
    auto head=mHeader->next;
    auto tail=head;
    for(size_t i=1;i<(mSize+1)/2;i++){
        tail=tail->next;
    }

    auto head2=tail->next;
    auto tail2=mHeader->prev;

    list1.mHeader->prev->next=head;
    head->prev = list1.mHeader->prev;
    list1.mHeader->prev=tail;
    tail->next = list1.mHeader;
    list1.mSize+=(mSize+1)/2;
    mSize-=(mSize+1)/2;

    mHeader->next=mHeader;
    mHeader->prev=mHeader;
    if(mSize==0)return;
    list2.mHeader->prev->next=head2;
    head2->prev = list2.mHeader->prev;
    list2.mHeader->prev=tail2;
    tail2->next = list2.mHeader;
    list2.mSize+=(mSize)/2;

    mSize=0;
}
