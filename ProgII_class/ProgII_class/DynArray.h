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
	//Constructors, normal, copia i reserva memòria(memory)
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
			
			TYPE* tmp = data;
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

	
	//At(int)- Retorna el valor de la posició que li dones
	TYPE& At(uint position) const { //UINT NI CONST NI REFERENCIA
		if (position > capacity){
			printf("No position");
		}
		return data[position];
	}

	//Empty- Mira si l'array està buida
	bool Empty()const{
		return num_elem == 0;
	}

	//clear- posa l'array a 0;
	void Clear(){
		num_elem = 0;
	}

	TYPE& operator[](uint position)const{ //PUTO UINT NI CONST NI REFERENCIA
		assert(position < num_elem);
			return data[position];
		
	}

	const DynArray& operator= (const DynArray& new_array){
		if (new_array.capacity>capacity){
			delete[] data;
			data = new TYPE[new_array.capacity];
		}
		memcpy(data, new_array.data, new_array.num_elem*sizeof(TYPE));
	}

	const DynArray& operator+=(const DynArray& new_array){

	}

	bool PopBack(TYPE& value){//Aqui la fai referència perquè aixi retorna el valor que hi ha.

		if (num_elem>0){
			value = data[--num_elem]
				return true;
		}
		return false;
		
	}



	void ShrinkToFit(){
		if(capacity != num_elem){
			TYPE* tmp = data;
			capacity = num_elem;
			data = new TYPE[num_elem];
			memcpy(data, tmp, num_elem*sizeof(TYPE);
			delete[] tmp;
		}
	}

	void Flip(){
		TYPE* tmp = data;
		data = new TYPE[num_elem];
		
	}

	void Insert(const uint& position, const TYPE& new_array){
		
		if (pos > num_elem){

		}
		for (int i = num_elem ; position < i ; i--){
			data[i] = data[i - 1];
		}
		data[position] = new_array;
		num_elem++:
	
	}

	void Insert(uint position, const TYPE& new_data){//Marti
		
		num_elem++;
		TYPE* tmp = data;
		
		if (capacity < num_elem){
			data = new TYPE[num_elem];
			capacity++;
			memcpy(data, tmp, (position)*sizeof(TYPE));

		}
	}

	TYPE* GetFirst(){
		return At(0);
	}
};

template <class TYPE>
class p2Queue{
private:
	DynArray<TYPE> start;

public:

	void Push(const TYPE& new_data){
		start.PushBack(new_data);
	}

	void Pop(TYPE& data){
		static int i= 0;
		start.At(i);
		i++;
	
	}

};

#endif