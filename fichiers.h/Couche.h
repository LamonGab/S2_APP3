/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include <iostream>
#include "Vecteur.h"

#define Premier 0
#define Avant 1
#define Apres 2
#define Dernier 3

using namespace std;

class Couche :public Vecteur<Forme*>
{
private:
	Forme* *tableauFormes;
	Vecteur<Forme*> formes;
	int etat; //Active=1, Inactive=2, Initialisee=3
public:
	Couche();
	~Couche();
	bool  changerEtat(int etat1);
	bool ajoutForme(Forme *figure);
	Forme *supprimerForme(int index);
	Forme *formeStocke(int index);
	double aireTotale();
	bool translation(int x, int y);
	bool viderCouche();
	void afficher(ostream & s);
	bool estActive();
	Couche get(int index);
	int get_taille();
};

#endif
