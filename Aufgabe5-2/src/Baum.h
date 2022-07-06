/*
 * Baum.h
 *
 *  Created on: 23 Jun 2022
 *      Author: Admin
 */

#ifndef BAUM_H_
#define BAUM_H_

#include <string>
#include <fstream>
using namespace std;

class Baum {
public:

	struct TreeNode{
		string vorname;
		string nachname;
		string zeichen;
		string vzeichen;
		TreeNode *vater;
		TreeNode *mutter;
		TreeNode *nachfahre;
	};

	TreeNode *wurzel = nullptr, *runptr = nullptr;
	TreeNode *newnode;
	string a;
	void wurzelknoten();
	void plusvater();
	void plusmutter();
	void zuvater();
	void zumutter();
	void zunachfahre();
	//void savetree(TreeNode *node);
	//void savetree2(TreeNode *node);
	void speichern();
	void einlesen();
	void printtree(TreeNode *node);
	void printtree2(TreeNode *node, int tiefe, char *pfad, bool vater);

	Baum();
	virtual ~Baum();
};

#endif /* BAUM_H_ */
