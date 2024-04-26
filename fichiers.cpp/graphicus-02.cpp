/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include <QApplication>
#include "monInterface.h"

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MonInterface gui("TestGraphicusGUI 1.0");
	return app.exec();
}

