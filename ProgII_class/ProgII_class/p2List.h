#ifndef _P2LIST_
#define _P2LIST_
#include "Definitions.h"

template<class TYPE>

struct Node{
public:
	Node<TYPE>* prev=NULL;
	Node<TYPE>* next=NULL;
	TYPE data = NULL;
	

	Node(const TYPE& data){
		this->data = data;
	}

	~Node(){}

};


template<class TYPE>

class p2List{
private:

	Node<TYPE>* start =  NULL;

public:
//Constructor
	p2List(){

	}

	//Destructor
	~p2List(){
		Clear();
	}

	Node<TYPE>* GetStart()const {
		return start;
	}

	void PushBack(const TYPE& new_data){
		Node<TYPE>* new_node = new Node<TYPE>(new_data);

		if (start == NULL){
			start = new_node;
			new_node->next = NULL;
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

		while (tmp){

			tmp = tmp->next;
			delete tmp->prev;
		}

		start = NULL;

	}

	const TYPE* Front() const{
		
		return this->start;

	}

	const TYPE* Back() const{
		Node<TYPE>* tmp=start;

		while (tmp->next){
			tmp = tmp->next;
		}

		return tmp->next;
	}

	void PushFront(const TYPE& new_data){
		Node<TYPE>* new_node = new Node<TYPE>(new_data);

		if (start == NULL){
			start = new_node;
			new_node->next = NULL;
		}
		else{
	
			new_node->next = start;
			start = new_node;
		}
	}

	void PopBack(TYPE& data){
		Node<TYPE>* tmp = start;
		while (tmp->next){
			tmp = tmp->next;
		}
		data = tmp->data;
		delete tmp;
	}

	void PopFront(TYPE& data){
		if (start == NULL){
			printf("List is empty!!!");
		}
		
		else
		{
			data = start->data;

			Node<TYPE>* tmp = start;
			start = start->next;
			start->prev = NULL;
			delete tmp;
		}
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

