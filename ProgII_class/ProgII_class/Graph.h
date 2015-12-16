#ifndef _GRAPH_
#define _GRAPH_

#include "Definitions.h"
//#include "DynArray.h"
#include "p2List.h"
#include <graph.h>


template <class TYPE>
class Graph{
public:
		struct NodeGraph{
			TYPE data;
			p2List<NodeGraph*> links;

			NodeGraph(const TYPE& data){
				this->data = data;
			}
			NodeGraph(const NodeGraph& new_node){
				this->data = new_node->data;
				this->links = new_node->links;
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
	
	bool IsReachable(NodeGraph* origin, NodeGraph* destiny){
		bool ret = false;
		NodeGraph* new_origin = new NodeGraph(*origin);
		NodeGraph* new_destiny = new NodeGraph(*destiny);
		if (origin == NULL || destiny == NULL){//Existeix a?, existeix b?
			return ret;
		}
		else{
			if (origin == destiny || new_origin){
				ret = true;
				return ret;
			}
		}
		
		//si a==b
		//Si te no té links retorna false
		//Miro tots els links meus, si hi és true si no:
		//Em poso a una cua o una llista i vai als fills (No anar als fils que estan a la llista)
	}
	
};


#endif