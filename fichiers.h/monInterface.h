/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"
#include "Canevas.h"
#include "cercle.h"
#include "carre.h"
#include "rectangle.h"

class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void coucheTranslater(int deltaX, int deltaY);
	void formePremiere();
	void formeSuivante();
	void formePrecedente();
	void formeDerniere();
	void couchePremiere();
	void coucheSuivante();
	void couchePrecedente();
	void coucheDerniere();
	bool ouvrirFichier(const char* nom);
	bool sauvegarderFichier(const char* nomFichier);
	void coucheAjouter();
	void coucheRetirer();
	void coucheCacher();
	void retirerForme();
private:
	Canevas c;
	Informations info;
	void miseAJour();
};

#endif // MONINTERFACE_H