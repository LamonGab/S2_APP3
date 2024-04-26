#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include "Forme.h"

using namespace std;

template <class T> 
class Vecteur
{
private:
	int taille;
	int capacite;
	int item_courant;
	T* tableau;
public:
	Vecteur();
	~Vecteur();

	void afficherVecteur(ostream& s);
	bool ajout_item(T item);
	T supprimer_item(int index);
	T get_item(int index);
	void viderVecteur();
	bool vecteurVide();
	int capaciteVecteur();
	int tailleVecteur();
	T* getTableau();

	T& operator[](int index);
	void operator += (T t);
	friend ostream& operator << (ostream& ostr, const  Vecteur<T>& v);
	friend ifstream& operator >> (ifstream& istr, const  Vecteur<T>& v);
	int operator ++ ();
	int operator -- ();
	int operator = (int index);
};



template <typename T>
Vecteur<T>::Vecteur()
{
	item_courant = 0;
	tableau = new T[capacite];
	taille = 0;
	capacite = 1;
}

template <typename T>
Vecteur<T>::~Vecteur()
{
	delete[] tableau;
}

template <typename T>
bool Vecteur<T>::ajout_item(T figure)
{
	bool retour = true;
	if (taille == capacite)
	{
		capacite = capacite * 2;
		T* tableau2 = new T[capacite];
		for (int i = 0; i < taille; i++)
		{
			tableau2[i] = tableau[i];
		}
		delete[] tableau;
		tableau = tableau2;
	}

	tableau[taille] = figure;
	if (tableau[taille] == NULL)
	{
		retour = false;
	}
	taille++;
	return retour;
}

template <typename T>
T Vecteur<T>::supprimer_item(int index)
{
	if (index >= taille || index < 0)
	{
		return nullptr;
	}
	for (int i = index; i < taille - 1; i++)
	{
		tableau[i] = tableau[i + 1];
	}
	delete tableau[index];
	taille--;
	return tableau[index];
}

template <typename T>
T Vecteur<T>::get_item(int index)
{
	if (index < 0 || index >= taille)
	{
		return nullptr;
	}
	return tableau[index];
}

template <typename T>
void Vecteur<T>::viderVecteur()
{
	int longueur = taille;
	for (int i = 0; i < longueur; i++)
	{
		delete tableau[i];
		taille--;
	}
}

template <typename T>
bool Vecteur<T>::vecteurVide()
{
	bool retour = false;
	if (taille == 0)
	{
		retour = true;
	}
	return retour;
}

template <typename T>
int Vecteur<T>::capaciteVecteur()
{
	return capacite;
}

template <typename T>
int Vecteur<T>::tailleVecteur()
{
	return taille;
}

template <typename T>
void Vecteur<T>::afficherVecteur(ostream& s)
{
	for (int i = 0; i < taille; i++)
	{
		tableau[i]->afficher(s);
	}
}

template <typename T>
T* Vecteur<T>::getTableau()
{
	return tableau;
}

template <typename T>
T& Vecteur<T>::operator[](int index)
{
	if (index >= 0 || index <= taille)
	{
		return tableau[index];
	}
}

template <typename T> 
void Vecteur<T>::operator += (T t)
{
	if (taille >= capacite)
	{
		capacite *= 2;
		T* tmp = new T[capacite];

		for (int i = 0; i < taille; i++)
		{
			tmp[i] = tableau[i];
		}
		delete[] tableau;
		tableau = new T[capacite];
		tableau = tmp;
	}
	tableau[taille] = t;
	taille++;
}

template <typename T> 
ostream& operator << (ostream& ostr, const  Vecteur<T>& v)
{
	return ostr;
}

template <typename T> ifstream& operator >> (ifstream& istr, const Vecteur<T>& v)
{
	return istr;
}

template <typename T> int Vecteur<T>::operator ++ ()
{
	if (item_courant + 1 < taille)
	{
		return ++item_courant;
	}
	return -1;
}

template <typename T> int Vecteur<T>::operator -- ()
{
	if (item_courant - 1 > -1)
	{
		return -- item_courant;
	}
	return -1;
}

template <typename T> int Vecteur<T>::operator = (int index)
{
	if (index >= -1 && index < taille)
	{
		item_courant = index;
		return item_courant;
	}
}



#endif
