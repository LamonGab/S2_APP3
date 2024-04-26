/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef DESSIN_H
#define DESSIN_H

#include <iostream>
#include "forme.h"
#include "Couche.h"

using namespace std;

class Canevas
{
private:
	Vecteur<Couche> couches;
	Vecteur<Forme*> formes;
	int coucheActive = 0;
	int nbCouches = 1;
public:
   Canevas();
   ~Canevas();
   bool reinitialiser();
   bool activerCouche(int index);
   bool cacherCouche(int index);
   bool ajouterForme(Forme *p_forme);
   bool retirerCouche(int index); 
   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);
   int initCoucheActive();
   int get_taille();
   bool supprimerCouche();
   void ajouterCouche(Couche* c);
   int get_coucheActive();
   void set_coucheActive(int index);
   int get_tailleCouche();

   friend ostream& operator << (ostream& ostr, const  Canevas& c);
   friend ifstream& operator >> (ifstream& istr, const  Canevas& c);
};

#endif
