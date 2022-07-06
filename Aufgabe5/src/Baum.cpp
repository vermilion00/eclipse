/*
 * Baum.cpp
 *
 *  Created on: 23 Jun 2022
 *      Author: Admin
 */

#include "Baum.h"
#include <iostream>
#include <string>

using namespace std;

#define space 5

Baum::Baum() {
	// TODO Auto-generated constructor stub

}

Baum::~Baum() {
	// TODO Auto-generated destructor stub
}

void Baum::wurzelknoten(){
	if(wurzel){
		cout << "Es wurde schon ein Wurzelknoten erstellt!" << endl;
	}else{
		newnode = new TreeNode;
		newnode->vater = nullptr;
		newnode->mutter = nullptr;
		newnode->nachfahre = nullptr;
		newnode->zeichen = ">>>";
		newnode->vzeichen = "-->";
		newnode->ausgegeben = false;
		wurzel = newnode;
		runptr = wurzel;
		string vorname;
		string nachname;
		cout << "Vorname: ";
		cin >> vorname;
		newnode->vorname = vorname;
		cout << "Nachname: ";
		cin >> nachname;
		newnode->nachname = nachname;
	}
}

void Baum::plusvater(){
	if(!wurzel){
		cout << "Erst muss ein Wurzelknoten erstellt werden!" << endl;
	}else{
		newnode = new TreeNode;
		runptr->vater = newnode;
		newnode->nachfahre = runptr;
		newnode->zeichen = "/--";
		newnode->vzeichen = "/--";
		newnode->ausgegeben = false;
		newnode->vater = nullptr;
		newnode->mutter = nullptr;
		string vorname;
		string nachname;
		cout << "Vorname: ";
		cin >> vorname;
		newnode->vorname = vorname;
		cout << "Nachname: ";
		cin >> nachname;
		newnode->nachname = nachname;
	}
}

void Baum::plusmutter(){
	if(!wurzel){
		cout << "Erst muss ein Wurzelknoten erstellt werden!" << endl;
	}else{
		newnode = new TreeNode;
		runptr->mutter = newnode;
		newnode->nachfahre = runptr;
		newnode->zeichen = "\\--";
		newnode->vzeichen = "\\--";
		newnode->ausgegeben = false;
		newnode->vater = nullptr;
		newnode->mutter = nullptr;
		string vorname;
		string nachname;
		cout << "Vorname: ";
		cin >> vorname;
		newnode->vorname = vorname;
		cout << "Nachname: ";
		cin >> nachname;
		newnode->nachname = nachname;
	}
}

void Baum::zuvater(){
	if(!wurzel){
		cout << "Erst muss ein Wurzelknoten erstellt werden!" << endl;
	}else if(!runptr->vater){
		cout << "Der Vaterknoten existiert nicht!" << endl;
	}else{
		runptr->zeichen = runptr->vzeichen;
		runptr = runptr->vater;
		runptr->zeichen = ">>>";

	}
}

void Baum::zumutter(){
	if(!wurzel){
		cout << "Erst muss ein Wurzelknoten erstellt werden!" << endl;
	}else if(!runptr->mutter){
		cout << "Der Mutterknoten existiert nicht!" << endl;
	}else{
		runptr->zeichen = runptr->vzeichen;
		runptr = runptr->mutter;
		runptr->zeichen = ">>>";
	}
}

void Baum::zunachfahre(){
	if(!wurzel){
		cout << "Erst muss ein Wurzelknoten erstellt werden!" << endl;
	}else if(!runptr->nachfahre){
		cout << "Sie befinden sich am Wurzelknoten!" << endl;
	}else{
		runptr->zeichen = runptr->vzeichen;
		runptr = runptr->nachfahre;
		runptr->zeichen = ">>>";
	}
}

void Baum::printtree(TreeNode *node){
    char pfad[255] = {};
    printtree2(node, 0, pfad, 0);
}

void Baum::printtree2(TreeNode *node, int tiefe, char *pfad, bool vater){
    if (node == 0){
        return;
    }
    tiefe++;
    printtree2(node->vater, tiefe, pfad, 1);

    if(tiefe > 1){
        pfad[tiefe-2] = 0;

        if(vater){
            pfad[tiefe-2] = 1;
        }
    }

    if(node->mutter){
        pfad[tiefe-1] = 1;
    }

    cout << endl;

    for(int i=0; i<tiefe-1; i++){
      if(i == tiefe-2){
          cout << "+";
      }else if(pfad[i]){
          cout << "|";
      }else{
          cout << " ";
      }
      for(int j=1; j<space; j++){
    	  if(i < tiefe-2){
    		  cout << " ";
    	  }else{
    		  cout << "-";
    	  }
      }
    }

    cout << node->zeichen << node->vorname << " " << node->nachname << endl;

    for(int i =  0; i < tiefe; i++){
      if(pfad[i]){
          cout << "|";
      }else{
          cout << " ";
      }
      for(int j = 1; j < space; j++){
          cout << " ";
      }
    }

    printtree2(node->mutter, tiefe, pfad, 0);
}









