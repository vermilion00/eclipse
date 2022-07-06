/*
 * DStack.cpp
 *
 *  Created on: 9 Jun 2022
 *      Author: Admin
 */

#include "DStack.h"
#include "DList.h"

DList list;
DStack::DStack() {
	// TODO Auto-generated constructor stub

}

DStack::~DStack() {
	// TODO Auto-generated destructor stub
}

void DStack::Push(double x){
	InsertAsFirstElement(x);
}

bool DStack::Pop(double &x){
	if(GetAndDeleteFirstElement(x)){
		return true;
	}else{
		return false;
	}
}

void DStack::SPrintReverse(DataListNode *a){
	if(a){
		DStack::SPrintReverse(a->ptr2next);
		cout << a->data << endl;
	}
}
