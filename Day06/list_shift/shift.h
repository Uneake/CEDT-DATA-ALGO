void shift(int k) {
	// TODO: Add your code here
	
	int plus=1;
	auto it = mHeader;
	if(k<0){
		k=-k;
		plus=-1;
	}
	k %= mSize;
	if(k==0)return;
	using std::cout;
	for(size_t i=0;i<=k;i++){
		if(plus>0)it=it->next;
		else it=it->prev;
	}

	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;
	if(plus<0)it = it->next;
	mHeader->next = it;
	mHeader->prev = it->prev;
	it->prev->next = mHeader;
	it->prev = mHeader;
}
