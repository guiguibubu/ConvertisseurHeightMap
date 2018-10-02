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

   ConvertisseurHeightMap convertisseurHeightMap;
   convertisseurHeightMap.lireFichierHeightMap();

   convertisseurHeightMap.calculerNormales();
   convertisseurHeightMap.construireTerrain(1.0f, 1.0f);
   convertisseurHeightMap.construireIndex();
   convertisseurHeightMap.enregistrerTout();

   cout << "--------------------------------------------" << endl;
   cout << "Valeurs lues dans la HeightMap puis converties :" << endl;
   cout << "--------------------------------------------" << endl;
   cout << convertisseurHeightMap << endl;
   
   // Maintenant on recupere les donnees sauvegardees
   cout << "--------------------------------------------" << endl;
   cout << "Valeurs lue dans la sauvegarde :" << endl;
   cout << "--------------------------------------------" << endl;
   Sauvegarde sauvegarde = Sauvegarde::Sauvegarde(ConvertisseurHeightMap::HEIGHTMAP_SAVEFILE_PATH_DEFAULT);
   sauvegarde.read();
   Terrain terrain = Terrain::Terrain(sauvegarde);

   cout << terrain << endl;

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