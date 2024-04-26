#ifndef CARRE_H
#define CARRE_H
#include <iostream>
#include "forme.h"

using namespace std;

class carre: public Forme
{
private:
	int cote;
public:
	carre(int xs=0, int ys=0, int cote_carre=0);
	~carre();
	double aire();
	void afficher(ostream & s);
	int getCote();
	void setCote(int nouveaucote);
};
#endif

