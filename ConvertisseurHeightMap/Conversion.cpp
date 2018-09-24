#include "ConvertisseurHeightMap.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

using namespace PM3D;

int main() {

   convertFloatIntoBinary(2.25125f);

   ConvertisseurHeightMap convertisseurHeightMap;
   convertisseurHeightMap.lireFichierHeightMap();

   cout << convertisseurHeightMap << endl;

   convertisseurHeightMap.construireTerrain(1.0f, 1.0f);
   convertisseurHeightMap.construireIndex();
   convertisseurHeightMap.calculerNormales();


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