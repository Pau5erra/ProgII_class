#include <iostream>
#include "p2List.h"


int main(){
	
	p2List<float> proba;
	float a = 1.0f;
	proba.PushBack(3.0f);
	proba.PushBack(4.0f);
	proba.PushBack(5.0f);
	proba.PushBack(6.0f);
	proba.PushBack(7.0f);

	proba.PushFront(2.0f);

	proba.Front();
	proba.Back();

	proba.PopBack(a);
	proba.PopFront(a);

	proba.Insert(2, 4.5f);
	proba.Remove(3);
	proba.Clear();

	return 0;
}