void buat_stack(pointer& Top) {
	Top = nullptr;
}

pointer peek(pointer Top) {
  return Top;
}

bool isEmpty(pointer Top) {
	if(Top == nullptr){
		return true;
	}else{
		return false;
	}
}

void push(pointer& Top, pointer pNew) {
  if(isEmpty(Top)){
  	Top = pNew;
  }else{
  	pNew->next = Top;
  	Top = pNew;
  }
}

pointer pop(pointer& Top) {
	pointer pDel;
	if(isEmpty(Top)){
		pDel = nullptr;
	}else if(Top->next == nullptr){
		pDel = Top;
		Top = nullptr;
	}else{
		pDel = Top;
		Top = Top->next;
		pDel->next = nullptr;
	}
	return pDel;
}