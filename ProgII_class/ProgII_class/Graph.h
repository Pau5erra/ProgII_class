#ifndef _GRAPH_
#define _GRAPH_

#include "Definitions.h"
#include "DynArray.h"
#include "p2List.h"

template <class TYPE>

struct NodeGraph{
private:
	TYPE data;
	DynArray<TYPE*> links;
public:

	NodeGraph(const TYPE& data){
		this->data = data;
	}

};

template <class TYPE>
class Graph{
private:
	p2List<NodeGraph*> nodes = NULL;

public:
	Graph(){}

	~Graph(){}

	int AddNode(const TYPE& new_data, NodeGraph* pare = NULL){
		NodeGraph<TYPE*> new_node = new NodeGraph<TYPE*>(new_data);
		
		if (pare != NULL){
			pare->links->PushBack(new_node);
		}

		nodes->PushBack(new_node);

		if (start == NULL)
			start = new_node;

		p2List<NodeGraph*> tmp = start;

		int position = 0;
		while (tmp->next){
			position++;
		}

		return position;
	}

	void LinkNodes(NodeGraph* pare, NodeGraph* fill){

		pare->links->PushBack(fill);

	}

	NodeGraph* GetNode( int position){
		p2List<NodeGraph*> tmp = start;
		int i = 0;
		while (tmp->next){

			if (position = i){
				break;
			}

			i++;
		}
		return tmp;
	}

};


#endif