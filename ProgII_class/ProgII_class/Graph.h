#ifndef _GRAPH_
#define _GRAPH_

#include "Definitions.h"
//#include "DynArray.h"
#include "p2List.h"


template <class TYPE>
class Graph{
public:
		struct NodeGraph{
			TYPE data;
			p2List<NodeGraph*> links;

			NodeGraph(const TYPE& data){
				this->data = data;
			}
			~NodeGraph(){}

			void Link(NodeGraph* children){
				this->links.PushBack(children);
			}
		};

private:
	p2List<NodeGraph*> nodes;


public:
	Graph(){}

	~Graph(){}
	
	NodeGraph* AddNode(const TYPE& new_data){
		NodeGraph* new_node = new NodeGraph(new_data);
		nodes.PushBack(new_node);

		return new_node;
	}
	
	bool GoTo(NodeGraph* origin, NodeGraph* destiny){

		//Existeix a?, existeix b?
		//si a==b
		//Si te no té links retorna false
		//Miro tots els links meus, si hi és true si no:
		//Em poso a una cua o una llista i vai als fills (No anar als fils que estan a la llista)
	}
	
};


#endif