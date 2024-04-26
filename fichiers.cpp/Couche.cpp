/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "Couche.h"

Couche::Couche()
{
	etat=1;
}

Couche::~Couche()
{
}

bool Couche::changerEtat(int etat1)
{
	bool retour=false;
	if(etat!=etat1)
	{
		etat=etat1;
		retour=true;
	}
	return retour;
}

bool Couche::ajoutForme(Forme *figure)
{
	if(etat!=1)
	{
		return false;
	}
	return formes.ajout_item(figure);
}

Forme *Couche::supprimerForme(int index)
{
	if(etat!=1)
	{
		return NULL;
	}
	return formes.supprimer_item(index);
}

Forme *Couche::formeStocke(int index)
{
	return formes.get_item(index);
}

double Couche::aireTotale()
{
	double aire=0;
	int taille= formes.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		aire+= formes.getTableau()[i]->aire();
	}
	return aire;
}

bool Couche::translation(int x, int y)
{
	bool retour=true;
	if(etat!=1)
	{
		retour=false;
	}
	int taille= formes.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		formes.getTableau()[i]->translater(x, y);
	}
	return retour;
}

bool Couche::viderCouche()
{
	bool retour=true;
	formes.viderVecteur();
	if(aireTotale()!=0)
	{
		retour=false;
	}
	return retour;
}

void Couche::afficher(ostream & s)
{
	int taille= formes.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		formes.getTableau()[i]->afficher(s);
	}
}

bool Couche::estActive()
{
	bool retour=false;
	if(etat==1)
	{
		retour=true;
	}
	return retour;
}


int Couche::get_taille()
{
	return formes.tailleVecteur();
}