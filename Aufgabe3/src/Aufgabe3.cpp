#include <iostream>
#include <time.h>
using namespace std;

struct DataListNode{
	int data;
	DataListNode *ptr2next;
};

time_t t;

DataListNode *anchor = NULL;
DataListNode *runptr = NULL;
int new_data;
DataListNode *new_node, *node2delete;
char eingabe;
void InsertAtBeginning();
void InsertAtEnd();
void InsertSorted();
void PrintListForward();
void BubbleSort();
int count = 0;

int main() {
	time(&t);
	srand((unsigned int) t);

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
				count++;
				InsertAtBeginning();
				break;

			case 'e':
				new_data = 1 + rand() % 999;
				count++;
				InsertAtEnd();
				break;

			case 'i':
				new_data = 1 + rand() % 999;
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
	new_node = new DataListNode;
	new_node->ptr2next = anchor;
	anchor = new_node;
	runptr = anchor;
	while(runptr->ptr2next && runptr->ptr2next->data < new_data){
		runptr->data = runptr->ptr2next->data;
		runptr = runptr->ptr2next;
	}
	runptr->data = new_data;
}

void InsertAtEnd(){
	new_node = new DataListNode;
	new_node->ptr2next = anchor;
	anchor = new_node;
	runptr = anchor;
	while(runptr->ptr2next){
		runptr->data = runptr->ptr2next->data;
		runptr = runptr->ptr2next;
	}
	runptr->data = new_data;
}












