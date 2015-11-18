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
			
			delete tmp->prev;
			tmp = tmp->next;
			
		}

		start = NULL;

	}

	const Node<TYPE>* Front() const{
		
		return this->start;

	}

	const Node<TYPE>* Back() const{
		Node<TYPE>* tmp=start;

		while (tmp->next){
			tmp = tmp->next;
		}

		return tmp;
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
		const Node<TYPE>* tmp = Back();

		data = tmp->data;//Em guardo data
		

		Node<TYPE>* tmp1 = start;
		//Se que estic iterant la llista dos vegades, però no se moltbé com posar el el next del penultim node a NULL
		while (tmp1->next){
			tmp1 = tmp1->next;
		}
		
		tmp1 = tmp1->prev;
		tmp1->next = NULL;
		delete tmp;
	}

	void PopFront(TYPE& data){
		if (start == NULL){
			printf("List is empty!!!");
		}
		
		else
		{
			data = start->data; // em guardo data

			Node<TYPE>* tmp = start;
			start = start->next;
			start->prev = NULL;
			delete tmp;
		}
	}

	void Insert(uint position, const TYPE& new_data) const{
		
		if (start == NULL){
			printf("List is empty!!!");
		}
		else{
			Node<TYPE>* new_node = new Node<TYPE>(new_data);
			Node<TYPE>* tmp = start;

			for (int i = 0 ; i < position-1; i++){
				tmp = tmp->next;
			}
			new_node->next = tmp->next;
			tmp->next = new_node;
			new_node->prev = tmp;

			new_node = new_node->next;
			new_node->prev = tmp->next;

		}
	}

	void Remove(uint position){
		if (start == NULL){
			printf("List is empty!!!");
		}
		else{
			Node<TYPE>* tmp = start;
			Node<TYPE>* tmp1;
			for (int i = 0; i < position-2; i++){
				tmp = tmp->next;
			}
			tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			tmp = tmp->next;
			tmp->prev = tmp->prev->prev;
			delete tmp1;
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

