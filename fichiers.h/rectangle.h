#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "forme.h"

using namespace std;

class rectangle: public Forme
{
private:
	int longueur;
	int largeur;
public:
	rectangle(int xr=0, int yr=0, int longueur_rectangle=0, int largeur_rectangle=0);
	~rectangle();
	double aire();
	void afficher(ostream & s);
	int getLongueur();
	void setLongueur(int nouvelleLongueur);
	int getLargeur();
	void setLargeur(int nouvelleLargeur);
};
#endif
	
