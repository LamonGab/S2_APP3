#define _USE_MATH_DEFINES
#ifndef CERCLE_H
#define CERCLE_H
#include <iostream>
#include "forme.h"
#include <cmath>

using namespace std;

class cercle: public Forme
{
private:
	int rayon;
public:
	cercle(int xc=0, int yc=0, int rayon_cercle=0);
	~cercle();
	double aire();
	void afficher(ostream & s);
	int getRayon();
	void setRayon(int nouveauRayon);
};
#endif

