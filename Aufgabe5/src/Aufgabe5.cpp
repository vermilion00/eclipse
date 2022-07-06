#include <iostream>
#include <cctype>
#include "Baum.h"
using namespace std;

void aufforderung();
void inputauswahl(char x);
//void speichern();
//void einlesen();

char input;

Baum b;

int main() {
	while(true){
		aufforderung();
		cin >> input;
		inputauswahl(input);
		b.printtree(b.wurzel);
	}
	return 0;
}

void inputauswahl(char x){
	x = tolower(x);
	switch(x){
		case 'r':
			b.wurzelknoten();
			break;
		case 'v':
			b.plusvater();
			break;
		case 'm':
			b.plusmutter();
			break;
		case 's':
			//speichern();
			break;
		case 'f':
			//einlesen();
			break;
		case 'd':
			b.zuvater();
			break;
		case 'a':
			b.zumutter();
			break;
		case 'w':
			b.zunachfahre();
			break;
	}
}

void aufforderung(){
	cout << endl;
	cout << "Auswahl:" << endl;
	cout << "R: Erstellen eines Wurzelknotens" << endl;
	cout << "V: Vater hinzufuegen" << endl;
	cout << "M: Mutter hinzufuegen" << endl;
	cout << "D: Gehe nach unten zu Vater" << endl;
	cout << "A: Gehe nach unten zu Mutter" << endl;
	cout << "W: Gehe nach oben zu Nachfahre" << endl;
	cout << "S: Speichern des Stammbaums" << endl;
	cout << "F: Einlesen eines Stammbaums" << endl;
	cout << "Geben sie ihre Auswahl ein: ";
}
