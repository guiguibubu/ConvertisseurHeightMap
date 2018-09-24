#include "Terrain.h"
#include <iostream>

namespace PM3D {

   void Terrain::initIndex() {

      for (int y = 0; y < nbLignes - 1; ++y) {
         for (int x = 0; x < nbColonnes - 1; ++x) {
            // on tourne dans le sens horaire
            // triangle du bas a droite
            pIndices.push_back(y * nbColonnes + x);
            pIndices.push_back((y + 1) * nbColonnes + (x + 1));
            pIndices.push_back(y * nbColonnes + (x + 1));
            // triangle du haut a gauche
            pIndices.push_back(y * nbColonnes + x);
            pIndices.push_back((y + 1)* nbColonnes + x);
            pIndices.push_back((y + 1)* nbColonnes + (x + 1));
         }
      }
   }

   void Terrain::initListeTriangle() {
      for (int index : pIndices) {
         listeTriangle.push_back(sommets[index]);
      }
   }

   std::vector<SommetTerrain> Terrain::getListeTriangle() {
      return listeTriangle;
   }
}
