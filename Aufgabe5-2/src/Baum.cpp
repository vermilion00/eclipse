/*
 * Baum.cpp
 *
 *  Created on: 23 Jun 2022
 *      Author: Admin
 */

#include "Baum.h"
#include <iostream>
#include <fstream>
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
		a.append("r");
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
		a.append("v");
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
		a.append("m");
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
		a.append("d");
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
		a.append("a");
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
		a.append("w");
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

/*void Baum::savetree(TreeNode *node){
	savefile.open("savefile.dat");
	savefile << a << endl;
	savetree2(node);
}

void Baum::savetree2(TreeNode *node){
	if (!node){
		return;
	}
	savetree2(node->vater);
	savefile << node->vorname << "|" << node->nachname << "|" << endl;
	//savefile << &node << endl << node->vater << endl << node->mutter << endl << node->nachfahre << endl << endl;
	savetree2(node->mutter);
}*/

void Baum::speichern(){
	ofstream savefile;
	savefile.open("savefile.dat");
	savefile << a << endl;
	string b = a;
	runptr = wurzel;
	while(!b.empty()){
		switch(b[0]){
			case 'r':
				savefile << runptr->vorname << "|" << runptr->nachname << "|" << endl;
				break;

			case 'v':
				runptr = runptr->vater;
				savefile << runptr->vorname << "|" << runptr->nachname << "|" << endl;
				runptr = runptr->nachfahre;
				break;

			case 'm':
				runptr = runptr->mutter;
				savefile << runptr->vorname << "|" << runptr->nachname << "|" << endl;
				runptr = runptr->nachfahre;
				break;

			case 'd':
				runptr = runptr->vater;
				break;

			case 'a':
				runptr = runptr->mutter;
				break;

			case 'w':
				runptr = runptr->nachfahre;
				break;

			case 'f':
				runptr = wurzel;
				break;
		}
		b.erase(0, 1);
	}
	savefile.close();
}

void Baum::einlesen(){
	ifstream readfile;
	readfile.open("savefile.dat");
	//readfile.seekg(0, ios::beg);
	getline(readfile, a);
	string b = a;
	a.append("f");
	string vorname;
	string nachname;
	string tmp;
	int k = 0;
	while(getline(readfile, tmp)){
		while(b[0] == 'a' || b[0] == 'd' || b[0] == 'w' || b[0] == 'f'){
			switch(b[0]){
				case 'a':
					runptr = runptr->mutter;
					break;

				case 'd':
					runptr = runptr->vater;
					break;

				case 'w':
					runptr = runptr->nachfahre;
					break;

				case 'f':
					runptr = wurzel;
					break;
			}
			b.erase(0, 1);
		}
		switch(b[0]){
			case 'r':
				newnode = new TreeNode;
				newnode->vater = nullptr;
				newnode->mutter = nullptr;
				newnode->nachfahre = nullptr;
				newnode->zeichen = ">>>";
				newnode->vzeichen = "-->";
				wurzel = newnode;
				runptr = wurzel;
				while(tmp[k] != '|'){
					vorname += tmp[k];
					k++;
				}
				newnode->vorname = vorname;
				vorname = "";
				k++;
				while(tmp[k] != '|'){
					nachname += tmp[k];
					k++;
				}
				k = 0;
				newnode->nachname = nachname;
				nachname = "";
				break;

			case 'v':
				newnode = new TreeNode;
				runptr->vater = newnode;
				newnode->nachfahre = runptr;
				newnode->zeichen = "/--";
				newnode->vzeichen = "/--";
				newnode->vater = nullptr;
				newnode->mutter = nullptr;
				while(tmp[k] != '|'){
					vorname += tmp[k];
					k++;
				}
				newnode->vorname = vorname;
				vorname = "";
				k++;
				while(tmp[k] != '|'){
					nachname += tmp[k];
					k++;
				}
				k = 0;
				newnode->nachname = nachname;
				nachname = "";
				break;

			case 'm':
				newnode = new TreeNode;
				runptr->mutter = newnode;
				newnode->nachfahre = runptr;
				newnode->zeichen = "\\--";
				newnode->vzeichen = "\\--";
				newnode->vater = nullptr;
				newnode->mutter = nullptr;
				while(tmp[k] != '|'){
					vorname += tmp[k];
					k++;
				}
				newnode->vorname = vorname;
				vorname = "";
				k++;
				while(tmp[k] != '|'){
					nachname += tmp[k];
					k++;
				}
				k = 0;
				newnode->nachname = nachname;
				nachname = "";
				break;
		}
		b.erase(0, 1);
	}
	runptr = wurzel;
}







