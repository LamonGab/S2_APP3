/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "Canevas.h"

Canevas::Canevas()
{
	couches += new Couche();
	couches.get_item(coucheActive)->changerEtat(1);
}

Canevas::~Canevas()
{
	reinitialiser();
}

bool Canevas::reinitialiser()
{
	coucheActive = 0;
	nbCouches = 1;
	couches.viderVecteur();
	couches += new Couche();
	couches[coucheActive]->changerEtat(1);
	return true;
}


bool Canevas::activerCouche(int index)
{
	if (index >= nbCouches || index < 0)
	{
		return false;
	}
	else if (index == coucheActive)
	{
		couches.get_item(coucheActive)->changerEtat(2);
		coucheActive = -1;
		couches = coucheActive;
		return true;
	}
	else if (coucheActive == -1)
	{
		coucheActive = index;
		couches.get_item(coucheActive)->changerEtat(1);
		couches = coucheActive;
		return true;
	}
	else
	{
		couches.get_item(coucheActive)->changerEtat(2);
		coucheActive = index;
		couches.get_item(coucheActive)->changerEtat(1);
		couches = coucheActive;
		return true;
	}
}

bool Canevas::cacherCouche(int index)
{
	bool retour=true;
	if(index<0 || index>= nbCouches)
	{
		retour=false;
	}
	couches[index]->changerEtat(2);
	return retour;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	couches[coucheActive]->ajoutForme(p_forme);
	return true;
}

bool Canevas::retirerCouche(int index)
{
	couches.supprimer_item(index);
	nbCouches--;
	couches = -1;
	return true;
}

double Canevas::aire()
{
	double aire=0;
	for(int i=0; i< nbCouches; i++)
	{
		aire=aire+couches[i]->aireTotale();
	}
	return aire;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	couches[coucheActive]->translation(deltaX, deltaY);
	return true;
}

void Canevas::afficher(ostream & s)
{
	for(int i=0; i< nbCouches; i++)
	{
		if(couches[i]->aireTotale()==0)
		{
			s << "----- Couche " << i << endl << "Couche initialisee" << endl;
		}
		else
		{
			s << "----- Couche " << i << endl;
			couches[i]->afficher(s);
		}
	}
}

ostream& operator << (ostream& ostr, Canevas& c)
{
	c.afficher(ostr);
	return ostr;
}

ifstream& operator >> (ifstream& istr, const  Canevas& c)
{
	return istr;
}

int Canevas::initCoucheActive()
{
	if (coucheActive == -1)
	{
		return -1;
	}

	if (coucheActive == 0)
	{
		activerCouche(1);
		couches.get_item(coucheActive)->viderCouche();
	}
	else
	{
		activerCouche(0);
		couches.get_item(coucheActive)->viderCouche();
	}
	return coucheActive;
}

int Canevas::get_coucheActive()
{
	return coucheActive;
}


void Canevas::set_coucheActive(int index)
{
	coucheActive = index;
}

int Canevas::get_tailleCouche()
{
	return formes.tailleVecteur();
}

int Canevas::get_taille()
{
	int nbFormes = 0;
	for (int i = 0; i < nbCouches; i++)
	{
		activerCouche(i);
		nbFormes += get_tailleCouche();
	}
	activerCouche(coucheActive);
	return nbFormes;
}