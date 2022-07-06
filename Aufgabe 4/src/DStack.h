/*
 * DStack.h
 *
 *  Created on: 9 Jun 2022
 *      Author: Admin
 */

#ifndef SRC_DSTACK_H_
#define SRC_DSTACK_H_

#include <iostream>
#include "DList.h"
using namespace std;

class DStack : public DList{
public:

	/*struct DataListNode{
		double data;
		DataListNode *ptr2next;
	};

	DataListNode *anchor = nullptr;
	DataListNode *runptr = nullptr;
	int new_data;
	DataListNode *new_node, *node2delete;

	void Push(double x){
		new_node = new DataListNode;
		new_node->ptr2next = anchor;
		new_node->data = x;
		anchor = new_node;
	}

	bool Pop(double &x){
		if(anchor != nullptr){
			x = anchor->data;
			node2delete = anchor;
			anchor = anchor->ptr2next;
			delete node2delete;
			return true;
		}
		return false;
	}

	void SPrintReverse(DataListNode *a){
		if(a->ptr2next){
			SPrintReverse(a->ptr2next);
		}
		cout << a->data << endl;
	} */

	DStack();
	virtual ~DStack();

	void Push(double x);
	bool Pop(double &x);
	void SPrintReverse(DataListNode *a);
};

#endif /* SRC_DSTACK_H_ */
