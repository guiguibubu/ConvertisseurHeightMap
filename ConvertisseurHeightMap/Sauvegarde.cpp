#include "Sauvegarde.h"
#include <fstream>
#include <direct.h>

void Sauvegarde::save() {
   //Creation du dossier de sauvegarde
   _mkdir(".\\..\\Save");

   std::ofstream fileOutputStream{ saveFilePath };

   saveLigneColonneDxDy(fileOutputStream);
   for (unsigned int indice : pIndices) {
      saveIndice(fileOutputStream, indice);
   }
   fileOutputStream << std::endl;
   for (PM3D::SommetTerrain sommet : listeTriangle) {
      saveSommet(fileOutputStream, sommet);
   }
   fileOutputStream.close();
}

void Sauvegarde::read() {
   // On s'assure que les vecteurs sont vide avant de les remplir
   pIndices.clear();
   listeTriangle.clear();

   std::ifstream fileInputStream{ saveFilePath };

   readLigneColonneDxDy(fileInputStream);
   int nbTriangle = (nbColonnes - 1) * (nbLignes - 1) * 2;
   for (int i = 0; i < nbTriangle*3; i++) {
      pIndices.push_back(readIndice(fileInputStream));
   }
   for (int i = 0; i < nbTriangle*3; i++) {
      PM3D::SommetTerrain sommet = readSommet(fileInputStream);
      listeTriangle.push_back(sommet);
   }

   fileInputStream.close();
}

void Sauvegarde::saveLigneColonneDxDy(std::ostream& stream) {
   stream << nbLignes << " " 
      << nbColonnes << " "
      << dx << " "
      << dy << " "
      << std::endl;
}

void Sauvegarde::saveIndice(std::ostream& stream, unsigned int indice) {
   stream << indice << " ";
}

void Sauvegarde::saveSommet(std::ostream& stream, PM3D::SommetTerrain sommet) {
   stream << sommet.position.x << " ";
   stream << sommet.position.y << " ";
   stream << sommet.position.z << " ";
   stream << sommet.normal.x << " ";
   stream << sommet.normal.y << " ";
   stream << sommet.normal.z << " ";
   stream << std::endl;
}

void Sauvegarde::readLigneColonneDxDy(std::istream& stream) {
   stream >> nbLignes;
   stream >> nbColonnes;
   stream >> dx;
   stream >> dy;
}

unsigned int Sauvegarde::readIndice(std::istream& stream) {
   unsigned int indice;
   stream >> indice;
   return indice;
}

PM3D::SommetTerrain Sauvegarde::readSommet(std::istream& stream) {
   PM3D::SommetTerrain sommet;
   stream >> sommet.position.x;
   stream >> sommet.position.y;
   stream >> sommet.position.z;
   stream >> sommet.normal.x;
   stream >> sommet.normal.y;
   stream >> sommet.normal.z;
   return sommet;
}