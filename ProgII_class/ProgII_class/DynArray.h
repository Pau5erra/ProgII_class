#ifndef _DYNARRAY_
#define _DYNARRAY_

#include "Definitions.h"
#define BLOCK 20

template <class TYPE>

class DynArray{
private:

	uint capacity=BLOCK;
	uint num_elem=0;
	TYPE* data=NULL;

public:
	//Constructors, normal, copia i reserva mem�ria(memory)
	DynArray(){
		data = new TYPE[capacity];
	}

	DynArray(const DynArray& new_array){
		capacity = MAX(capacity, new_array.num_elem);
		num_elem = new_array.num_elem;
		data = new TYPE[new_array.capacity];
		memcpy(data, new_array.data, new_array.num_elem*sizeof(TYPE));

	}

	DynArray(uint new_capacity){
		if (capacity < new_capacity){
			capacity = new_capacity;
		}
		data = new TYPE[capacity];
	}
	//Destructor
	~DynArray(){
		if (data != NULL){
			delete[] data;
		}
	}
	//PushBack(element)- afegeic alguna cosa al final de la cadena
	void PushBack(const TYPE& new_element){
		if (capacity<num_elem){
			TYPE* tmp = new tmp[capacity];
			data = new TYPE[capacity + BLOCK];
			mempcy(data, tmp, num_elem*sizeof(TYPE));
			delete[] tmp;

		}

		data[num_elem++] = new_element;
	}
	//Capacity- retorna la capacitat
	uint Capacity(){
		return capacity;
	}
	//Size- retorna el numero d'elements
	uint Size(){
		return num_elem;
	}

	
	//At(int)- Retorna el valor de la posici� que li dones
	TYPE& At(const uint& position) const {
		if (position > capacity){
			printf("No position");
		}
		return data[position];
	}
	//Empty- Mira si l'array est� buida
	bool Empty()const{
		return num_elem == 0;
	}
	//clear- posa l'array a 0;
	void Clear(){
		num_elem = 0;
	}

};
#endif