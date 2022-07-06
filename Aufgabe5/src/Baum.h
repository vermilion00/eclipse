/*
 * Baum.h
 *
 *  Created on: 23 Jun 2022
 *      Author: Admin
 */

#ifndef BAUM_H_
#define BAUM_H_

#include <string>
using namespace std;

class Baum {
public:

	struct TreeNode{
		string vorname;
		string nachname;
		string zeichen;
		string vzeichen;
		bool ausgegeben;
		TreeNode *vater;
		TreeNode *mutter;
		TreeNode *nachfahre;
	};

	TreeNode *wurzel = nullptr, *runptr = nullptr;
	TreeNode *newnode;

	void wurzelknoten();
	void plusvater();
	void plusmutter();
	void zuvater();
	void zumutter();
	void zunachfahre();
	void printtree(TreeNode *node);
	void printtree2(TreeNode *node, int tiefe, char *pfad, bool vater);

	Baum();
	virtual ~Baum();
};

#endif /* BAUM_H_ */
