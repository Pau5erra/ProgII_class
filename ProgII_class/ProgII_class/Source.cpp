#include <iostream>
#include "p2List.h"


int main(){
	//Proves llista
	p2List<float> proba_llista;
	float a_ll = 1.0f;
	proba_llista.PushBack(3.0f);
	proba_llista.PushBack(4.0f);
	proba_llista.PushBack(5.0f);
	proba_llista.PushBack(6.0f);
	proba_llista.PushBack(7.0f);
		 
	proba_llista.PushFront(2.0f);
		
	proba_llista.Front();
	proba_llista.Back();
		
	proba_llista.PopBack(a_ll);
	proba_llista.PopFront(a_ll);
		 
	proba_llista.Insert(2, 4.5f);
	proba_llista.Remove(3);
	proba_llista.Clear();

	//Probes pila
	p2Stack<float> proba_pila;
	float a_p = 1.0f;
	proba_pila.Push(1.0f);
	proba_pila.Push(2.0f);

	proba_pila.Pop(a_p);

	return 0;
}