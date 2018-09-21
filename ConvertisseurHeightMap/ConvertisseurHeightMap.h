#ifndef CONVERTISSEUR_HEIGHTMAP_H

#define CONVERTISSEUR_HEIGHTMAP_H

#include "CSommetTerrain.h"
#include <list>
#include <string>
#include <iostream>
#include <math.h>

class ConvertisseurHeightMap {

private:
   std::list<CSommetTerrain> sommets; // liste des sommets
   int dx = 0, dy = 0; // dimenssion en X et en Y
   int nbSommets = 0;
   int nbPolygones = 0;
   std::string heightMapPath;
public:
   ConvertisseurHeightMap(std::string heightMapPath) : heightMapPath{ heightMapPath } {
      init();
   }; // Constructeur
   ConvertisseurHeightMap() : ConvertisseurHeightMap("./../Map/heightMap.txt") {}
      
   ~ConvertisseurHeightMap() = default; // Destructeur

   void lireFichierHeightMap();
   void construireTerrain(float echelleXY, float echelleZ);
   void calculerNormales();
   void construireIndex();
   void enregistrerTout();

private:
   int calculNbSommet() {
      return dx * dy;
   }
   int calculNbPolygones() {
      return std::pow((dx - 1) * (dy - 1), 2);
   }
   void init() {
      lireFichierHeightMap();
      nbSommets = calculNbSommet();
      nbPolygones = calculNbPolygones();

   }

   // Pour debugger
public:
   void afficherHeightMapPath(std::ostream& stream);
   void afficherNbLigne(std::ostream& stream);
   void afficherNbColonne(std::ostream& stream);
   void afficherNbSommets(std::ostream& stream);
   void afficherNbPolygone(std::ostream& stream);
   void afficherSommetsXYZ(std::ostream& stream);

   //// Permet d'afficher l'objet dans un flux via '<<'
   //friend  std::ostream& operator<< (std::ostream& _stream, ConvertisseurHeightMap& const mc) { 
   //   std::string textNbLigne = "Il y a " + dy + " colonnes";
   //      std::string textNbColonne

   //   _stream << "HI" << std::endl;  
   //   return _stream;  
   //}
};

#endif // !CONVERTISSEUR_HEIGHTMAP_H
