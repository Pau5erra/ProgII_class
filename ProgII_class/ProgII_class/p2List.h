#ifndef _P2LIST_
#define _P2LIST_
#include "Definitions.h"

template<class TYPE>

struct Node{
	friend class p2List;
private:
	Node<TYPE>* prev=NULL;
	Node<TYPE>* next=NULL;

public:

	TYPE data = NULL;
	

	Node(const TYPE& data){
		this->data = data;
	}

	~Node(){}

};

template<class TYPE>
class p2List{
private:

	Node<TYPE>* start=NULL;

public:
//Constructor
	p2List(){

	}

	//Destructor
	~p2List(){
		clear();
	}

	Node<TYPE>* GetStart()const {
		return start;
	}

	void PushBack(const TYPE& new_data){
		Node<TYPE>* new_node = new Node<TYPE>(new_data);

		if (start == NULL){
			start = new_node;
		}
		else{
			Node<TYPE>* tmp = start;

			while (tmp->next){
				tmp = tmp->next;
			}

			tmp->next = new_node;
			new_node->prev = tmp;
			new_node->next = NULL;

		}
	}

	bool Empty() const {
		
		return (start == NULL);

	}

	uint Size() const {
		
		uint num=0;
		Node<TYPE>* tmp = start;

		while (tmp == NULL){
			
			tmp = tmp->next;
			num++;

		}

		return num;
	}

	void Clear(){
		Node<TYPE>* tmp = start;

		while (tmp == NULL){

			tmp = tmp->next;
			delete tmp->prev;
		}

		start = NULL;

	}

};

//NOUS METODES PER DILLUNS
/*
front()- retorna un punter constant, és com el getstart, retorna el primer punter.
back()- retorna un punter constant i retorna l'últim punter
push_front()-Posa un node al principi
pop_back()-treu un node al final, retorna la data del node
pop_front()-treu el node del principi, retorna la data del node

insert(uint)- posar un node al mig.
remove(uint)- treu el node de la posició

*/

#endif

