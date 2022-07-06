/*
 * DList.h
 *
 *  Created on: 10 Jun 2022
 *      Author: Admin
 */

#ifndef SRC_DLIST_H_
#define SRC_DLIST_H_

#include <iostream>
using namespace std;

class DList {
public:

	struct DataListNode{
		double data;
		DataListNode *ptr2next;
	};

	DataListNode *anchor = nullptr;
	DataListNode *runptr = nullptr;
	int new_data;
	DataListNode *new_node, *node2delete;

	void InsertAsFirstElement(double x){
		new_node = new DataListNode;
		new_node->ptr2next = anchor;
		new_node->data = x;
		anchor = new_node;
	}

	bool GetAndDeleteFirstElement(double &x){
		if(anchor != nullptr){
			x = anchor->data;
			node2delete = anchor;
			anchor = anchor->ptr2next;
			delete node2delete;
			return true;
		}
		return false;
	}

	void SPrintForward(){
		runptr = anchor;
		while(runptr){
			cout << runptr->data << endl;
			runptr = runptr->ptr2next;
		}
	}

	DList();
	virtual ~DList();
};

#endif /* SRC_DLIST_H_ */
