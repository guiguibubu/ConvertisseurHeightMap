#include "ConvertisseurHeightMap.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void ConvertisseurHeightMap::lireFichierHeightMap() {

   ifstream in{ heightMapPath };
   
   int entierLu; // entier lu dans le fichier
   int indexLigne = 0;
   int indexColonne = 0;
   
   int i = 0;
   while (in >> entierLu) {
      // 1ere ligne correspond aux nombres de lignes
      if (i == 0) {
         dy = entierLu;
      }
      // 2eme ligne correspond aux nombres de colonnes
      else if (i == 1) {
         dx = entierLu;
      }
      // On lit la hauteurs pour chaque sommet suivant l'axe des "x" croissant puis l'axe des "y" croissants
      else {
         indexColonne = (i - 2) % dx;
         indexLigne = (i - 2) / dx;

         sommets.push_back(CSommetTerrain(indexColonne, indexLigne, entierLu));
      }
      i++;
   }
}

void ConvertisseurHeightMap::afficherSommetsXYZ(ostream& stream) {
   for (CSommetTerrain sommetTerrain : sommets) {
      stream << "x = " << sommetTerrain.getX()
         << "; y = " << sommetTerrain.getY()
         << "; z = " << sommetTerrain.getZ()
         << endl;
   }
}

void ConvertisseurHeightMap::afficherHeightMapPath(std::ostream& stream) {
  stream << "HeightMapPath : " << heightMapPath  << endl;
}
void ConvertisseurHeightMap::afficherNbLigne(std::ostream& stream) {
   stream << "Nb Ligne : " << dy << endl;
}
void ConvertisseurHeightMap::afficherNbColonne(std::ostream& stream) {
   stream << "Nb Colonne : " << dx << endl;
}
void ConvertisseurHeightMap::afficherNbSommets(std::ostream& stream) {
   stream << "Nb Sommet : " << nbSommets << endl;
}
void ConvertisseurHeightMap::afficherNbPolygone(std::ostream& stream) {
   stream << "Nb Polygone : " << nbPolygones << endl;
}