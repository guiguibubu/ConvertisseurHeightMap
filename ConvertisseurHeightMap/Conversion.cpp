#include "ConvertisseurHeightMap.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

int main() {

   ConvertisseurHeightMap convertisseurHeightMap;

   convertisseurHeightMap.afficherSommetsXYZ(cout);
   convertisseurHeightMap.afficherHeightMapPath(cout);
   convertisseurHeightMap.afficherNbLigne (cout);
   convertisseurHeightMap.afficherNbColonne(cout);
   convertisseurHeightMap.afficherNbSommets(cout);
   convertisseurHeightMap.afficherNbPolygone(cout);


   /*LireFichierHeightMap();
   ConstruireTerrain(1.0f, 1.0f);
   CalculerNormales();
   ConstruireIndex();
   EnregistrerTout();*/

   cout << "\n";
   cout << "--------------------------------------------" << endl;
   cout << "Appuyer sur 'Enter' pour fermer le programme" << endl;
   cout << "--------------------------------------------" << endl;
   string reponse;
   getline(cin, reponse);
   return 0;
}