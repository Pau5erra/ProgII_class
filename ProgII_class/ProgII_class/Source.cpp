#include <iostream>
#include "p2List.h"
#include "Graph.h"

int Factorial(int num){

		if (num > 1){
			return num*Factorial(num-1);
		}
		else{
			return 1;
		}

}

int main(){
	/*
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
	*/
	int result = 3;

	Factorial(result);


	Graph<int> proba_graph;
	
	proba_graph.AddNode(1);
	proba_graph.GetNode(1);
	proba_graph.AddNode(2, proba_graph.GetNode(1));
	
	
	return 0;
}

//LEs crides recursives sempre tenen una condició de sortida


