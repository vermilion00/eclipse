#include <iostream>
#include <time.h>
using namespace std;

struct DataListNode{
	int data;
	DataListNode *ptr2next;
	DataListNode *ptr2prev;
};

time_t t;

DataListNode *anchor = NULL;
DataListNode *ptr2first = NULL;
DataListNode *runptr = NULL;
int new_data;
DataListNode *new_node, *node2delete;
void InsertAtBeginning();
void InsertAtEnd();
void InsertSorted();
void PrintListForward();
void PrintListBackward();
void BubbleSort();
int count = 0;

int main() {
	time(&t);
	srand((unsigned int) t);
	char eingabe;
	cout << "Menü:" << endl;
	cout << "- a: Neues Element am Anfang der Liste" << endl;
	cout << "- e: Neues Element am Ende der Liste" << endl;
	cout << "- i: Neues Element in sortierte Liste einfügen" << endl;
	cout << "- s: Liste aufsteigend sortieren" << endl;
	cout << "- q: Programm verlassen" << endl;
	do{
		cout << "Wählen sie eine Funktion aus: ";
		cin >> eingabe;
		switch(eingabe){
			case 'a':
				new_data = 1 + rand() % 999;
				cout << "Neue Zahl: " << new_data << endl << "---" << endl;
				count++;
				InsertAtBeginning();
				break;

			case 'e':
				new_data = 1 + rand() % 999;
				cout << "Neue Zahl: " << new_data << endl << "---" << endl;
				count++;
				InsertAtEnd();
				break;

			case 'i':
				new_data = 1 + rand() % 999;
				cout << "Neue Zahl: " << new_data << endl << "---" << endl;
				count++;
				InsertSorted();
				break;

			case 's':
				BubbleSort();
				break;

			case 'q':
				cout << "Programm wird beendet." << endl << "Finale Liste:" << endl;
				break;
		}
		PrintListForward();
		PrintListBackward();
	}while(eingabe != 'q');

	while(anchor){
		node2delete = anchor;
		anchor = anchor->ptr2next;
		delete node2delete;
	}
	return 0;
}

void InsertAtBeginning(){
	new_node = new DataListNode;
	new_node->ptr2next = anchor;
	new_node->ptr2prev = NULL;
	if(count == 1){
		ptr2first = new_node;
	}else{
		new_node->ptr2next->ptr2prev = new_node;
	}
	new_node->data = new_data;
	anchor = new_node;
}

void PrintListForward(){
	runptr = anchor;
	while(runptr){
		cout << runptr->data << endl;
		runptr = runptr->ptr2next;
	}
}

void PrintListBackward(){
	runptr = ptr2first;
	cout << "---" << endl;
	while(runptr != NULL){
		cout << runptr->data << endl;
		runptr = runptr->ptr2prev;
	}
}

void BubbleSort(){
	int j = count;
	bool change = true;
	while((change == true) && (j > 0)){
		j--;
		change = false;
		runptr = anchor;
		for(int k = 0; k < j; ++k){
			if(runptr->data > runptr->ptr2next->data){
				int temp = runptr->data;
				runptr->data = runptr->ptr2next->data;
				runptr->ptr2next->data = temp;
				runptr = runptr->ptr2next;
				change = true;
			}else{
				runptr = runptr->ptr2next;
			}
		}
	}
}

void InsertSorted(){
	runptr = anchor;
	while(runptr && runptr->data < new_data){
		runptr = runptr->ptr2next;
	}
	new_node = new DataListNode;
	if(runptr == anchor && runptr == NULL){
			new_node->ptr2next = NULL;
			new_node->ptr2prev = NULL;
			ptr2first = new_node;
			anchor = new_node;
	}else if(runptr == anchor){
		new_node->ptr2prev = NULL;
		new_node->ptr2next = anchor;
		new_node->ptr2next->ptr2prev = new_node;
		anchor = new_node;
	}else if(runptr == NULL){
		new_node->ptr2next = NULL;
		new_node->ptr2prev = ptr2first;
		ptr2first->ptr2next = new_node;
		ptr2first = new_node;
	}else{
		new_node->ptr2prev = runptr->ptr2prev;
		new_node->ptr2next = runptr;
		runptr->ptr2prev->ptr2next = new_node;
		runptr->ptr2prev = new_node;
	}
	new_node->data = new_data;
}

void InsertAtEnd(){
	new_node = new DataListNode;
	if(anchor == NULL){
		anchor = new_node;
		new_node->ptr2prev = ptr2first;
		new_node->ptr2next = NULL;
	}else{
		ptr2first->ptr2next = new_node;
		new_node->ptr2prev = ptr2first;
		new_node->ptr2next = NULL;
	}
	ptr2first = new_node;
	new_node->data = new_data;
}












