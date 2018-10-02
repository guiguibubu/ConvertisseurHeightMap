#include "Terrain.h"
#include <iostream>
#include "toolsProjet.h"

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

   // Pour debugger

   void Terrain::afficherNbLigne(std::ostream& stream) {
      printIntoStream(stream, "Nb Ligne : " + std::to_string(nbLignes));
   }
   void Terrain::afficherNbColonne(std::ostream& stream) {
      printIntoStream(stream, "Nb Colonne : " + std::to_string(nbColonnes));
   }
   void Terrain::afficherPointeurIndices(std::ostream& stream) {
      printIntoStream(stream, "Liste indices : ", false);
      for (unsigned int indice : pIndices) {
         printIntoStream(stream, std::to_string(indice)+" ", false);
      }
   }
   void Terrain::afficherNbPolygone(std::ostream& stream) {
      printIntoStream(stream, "Nb Polygone : " + std::to_string(nbPolygones));
   }
   void Terrain::afficherListeTriangle(std::ostream& stream) {
      printIntoStream(stream, "Liste Triangles : ");
      for (SommetTerrain sommetTerrain : listeTriangle) {
         printIntoStream(stream, "x = " + std::to_string(sommetTerrain.position.x) + " y = " + std::to_string(sommetTerrain.position.y) + " z = " + std::to_string(sommetTerrain.position.z) + " nx = " + std::to_string(sommetTerrain.normal.x) + " ny = " + std::to_string(sommetTerrain.normal .y) + " nz = " + std::to_string(sommetTerrain.normal.z));
      }
   }
}
