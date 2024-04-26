#include "rectangle.h"

rectangle::rectangle(int xr, int yr, int longueur_rectangle, int largeur_rectangle)
{
	ancrage.x=xr;
	ancrage.y=yr;
	longueur=longueur_rectangle;
	largeur=largeur_rectangle;
}

rectangle::~rectangle()
{
}

double rectangle::aire()
{
	return longueur*largeur;
}

void rectangle::afficher(ostream & s)
{
	s << "R" << ancrage.x << " " << ancrage.y << " " << longueur << " " << largeur << endl;
}

int rectangle::getLongueur()
{
	return longueur;
}

void rectangle::setLongueur(int nouvelleLongueur)
{
	longueur=nouvelleLongueur;
}

int rectangle::getLargeur()
{
	return largeur;
}

void rectangle::setLargeur(int nouvelleLargeur)
{
	largeur=nouvelleLargeur;
}
