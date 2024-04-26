/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"


void Tests::tests_unitaires_formes()
{

	cercle cercle1(0,0,10);
	cercle1.afficher(cout);
	rectangle rectangle1(1,2,10,20);
	rectangle1.afficher(cout);
	carre carre1(1,3,5);
	carre1.afficher(cout);
	
   // Tests sur les formes geometriques
}

void Tests::tests_unitaires_vecteur()
{
	vecteur v;
	Forme* cercle1 = new cercle(0,0,2);
	Forme* cercle2 = new cercle(0,0,2);
	Forme* cercle3 = new cercle(0,0,2);
	Forme* cercle4 = new cercle(0,0,2);
	Forme* cercle5 = new cercle(0,0,2);
	Forme* cercle6 = new cercle(0,0,2);
	v.ajoutForme(cercle1);
	v.ajoutForme(cercle2);
	v.ajoutForme(cercle3);
	v.ajoutForme(cercle4);
	v.ajoutForme(cercle5);
	v.ajoutForme(cercle6);
	v.afficherVecteur(cout);
   // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{ 
	Couche couche1;
	Forme* cercle1 = new cercle(0,0,4);
	couche1.ajoutForme(cercle1);
	couche1.afficher(cout);
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
	
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
 //  tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   /*cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
   	cout << "----------------------------------------" << endl;
   	cout << endl << "Etapes 1 a 6" << endl;
   	Couche couche;
   	Canevas canevas;
	canevas.activerCouche(1);
	Forme* rectangle1 = new rectangle(0,0,2,3);
	Forme* carre1 = new carre(2,3,4);
	Forme* cercle1 = new cercle(7,8,6);
	canevas.ajouterForme(rectangle1);
	canevas.ajouterForme(carre1);
	canevas.ajouterForme(cercle1);
	canevas.activerCouche(2);
	Forme* rectangle2 = new rectangle(0,0,4,5);
	canevas.ajouterForme(rectangle2);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl <<"Etapes 7 a 13" << endl;
	canevas.activerCouche(0);
	Forme* rectangle3 = new rectangle(0,0,1,1);
	Forme* carre2 = new carre(0,0,1);
	Forme* cercle2 = new cercle(0,0,1);
	canevas.ajouterForme(rectangle3);
	canevas.ajouterForme(carre2);
	canevas.ajouterForme(cercle2);
	canevas.activerCouche(1);
	canevas.translater(5,5);
	canevas.activerCouche(2);
	canevas.retirerForme(0);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl <<"Etapes 14 a 16" << endl;
	canevas.activerCouche(1);
	canevas.retirerForme(0);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl <<"Etapes 17 a 19" << endl;
	canevas.reinitialiser();
	couche.viderCouche();
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << "Fin" << endl;*/
	Canevas canevas;
	Couche couche;
	cout << "----------------------------------------" << endl;
	canevas.activerCouche(0);
	Forme* rectangle1 = new rectangle(5,2,4,1);
	Forme* carre1 = new carre(6,2,2);
	Forme* carre2 = new carre(1,2,3);
	canevas.ajouterForme(rectangle1);
	canevas.ajouterForme(carre1);
	canevas.ajouterForme(carre2);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << "----------------------------------------" << endl << "Test 2" << endl;
	canevas.retirerForme(2);
	canevas.activerCouche(2);
	Forme* cercle1 = new cercle(1,0,4);
	canevas.ajouterForme(cercle1);
	canevas.activerCouche(1);
	Forme* cercle2 = new cercle(0,0,3);
	canevas.ajouterForme(cercle2);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;	
	cout << "----------------------------------------" << endl << "Test 3" << endl;
	canevas.activerCouche(0);
	canevas.retirerForme(0);
	canevas.retirerForme(0);
	canevas.activerCouche(1);
	canevas.translater(5,5);
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
	cout << "----------------------------------------" << endl << "Test 4" << endl;
	canevas.reinitialiser();
	canevas.afficher(cout);
	cout << endl << "Aire totale du canevas: " << canevas.aire() << endl;
	cout << "----------------------------------------" << endl;
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}

