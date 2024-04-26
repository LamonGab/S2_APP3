/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include <fstream>
#include "monInterface.h"
#include "forme.h"
#include "cercle.h"
#include "carre.h"
#include "rectangle.h"

using namespace std;
Informations info;
cercle ce;
rectangle r;
carre k;
Vecteur<Couche*> v;
Couche c;
Canevas ca;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	clearInformations();
	miseAJour();
}

void MonInterface::reinitialiserCanevas()
{
	c.reinitialiser();
	miseAJour();
}

/*bool MonInterface::ouvrirFichier(const char* nom)
{
	ifstream fichier;

	reinitialiserCanevas();

	fichier.open(nom);

	if (fichier.is_open())
	{
		string ligne;
		stringstream os2;
		char letter;
		char letter2;
		int x, y, l, h, c, r;
		int compte_couche = 0;

		getline(fichier, ligne);

		while (fichier.good())
		{
			os2 << ligne << endl;
			os2 >> letter;

			if (letter == 'L')
			{
				if (compte_couche == 0)
					ca.supprimerCouche();
				Couche* ptc = new Couche();
				ca.ajouterCouche(ptc);

				os2 >> letter2;

				if (letter2 == 'c')
				{
					ptc->cacher();
				}
				else if (letter2 == 'a')
				{
					ptc->changerEtat(1);
				}
				else if (letter2 == 'x')
				{
					ptc->changerEtat(2);
				}
				if (compte_couche != 0)
					ca.activerCouche(compte_couche);
				compte_couche++;
			}
			else if (letter == 'R' && compte_couche >= 0)
			{
				os2 >> x >> y >> l >> h;

				Forme* Rectangle = new rectangle(x, y, l, h);
				ca.ajouterForme(Rectangle);
			}
			else if (letter == 'K' && compte_couche >= 0)
			{
				os2 >> x >> y >> c;

				Forme* Carre = new carre(x, y, c);
				ca.ajouterForme(Carre);
			}
			else if (letter == 'C' && compte_couche >= 0)
			{
				os2 >> x >> y >> r;

				Forme* ptrc = new cercle(x, y, r);
				ca.ajouterForme(ptrc);
			}
			getline(fichier, ligne);
		}
		info.aireCanevas = ca.aire();
		info.nbCouches = compte_couche;
		info.nbFormesCouche = ca.get_taille();
		fichier.close();

		ostringstream os;
		ca.afficher(os);
		dessiner(os.str().c_str());
		setInformations(info);

		return true;
	}
	return false;
}*/

bool MonInterface::sauvegarderFichier(const char* nomFichier)
{
	bool retour = false;
	ofstream fichier;
	fichier.open(nomFichier);
	if (fichier.is_open())
	{
		fichier << c;
		fichier.close();
		retour=true;
	}
	return retour;
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	c.ajouterForme(new cercle(x, y, rayon));
	miseAJour();
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	c.ajouterForme(new rectangle(x, y, longueur, largeur));
	miseAJour();
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	c.ajouterForme(new carre(x, y, cote));
	miseAJour();
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	c.translater(deltaX, deltaY);
	miseAJour();
}

void MonInterface::formePremiere()
{
	c.formeActive(Premier);
	miseAJour();
}

void MonInterface::formeSuivante()
{
	c.formeActive(Apres);
	miseAJour();
}

void MonInterface::formePrecedente()
{
	c.formeActive(Avant);
	miseAJour();
}

void MonInterface::formeDerniere()
{
	c.formeActive(Dernier);
	miseAJour();
}

void MonInterface::couchePremiere()
{
	c.coucheActive(Premier);
	miseAJour();
}

void MonInterface::coucheSuivante()
{
	c.coucheActive(Apres);
	miseAJour();
}

void MonInterface::couchePrecedente()
{
	c.coucheActive(Avant);
	miseAJour();
}

void MonInterface::coucheDerniere()
{
	c.coucheActive(Dernier);
	miseAJour();
}

void coucheAjouter()
{
	c.ajouterCouche();
	miseAJour();
}

void coucheRetirer()
{
	c.retirerCouche();
	miseAJour();
}

void coucheCacher()
{
	c.cacherCouche();
	miseAJour();
}

void retirerForme()
{
	c.retirerForme();
	miseAJour();
}

void MonInterface::miseAJour()
{
	c.infosAJour(info);
	setInformations(info);
	stringstream os;
	os << c;
	dessiner(os.str().c_str());
}