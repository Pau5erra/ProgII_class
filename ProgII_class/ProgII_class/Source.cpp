#include <iostream>
#include "p2List.h"


int main(){
	
	p2List<int> proba;
	int a = 1;
	proba.PushBack(3);
	proba.PushBack(4);
	proba.PushBack(5);
	proba.PushFront(2);
	proba.PopBack(a);
	proba.PopFront(a);
	proba.Clear();

	return 0;
}