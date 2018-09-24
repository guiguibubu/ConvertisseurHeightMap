#ifndef CONVERTISSEUR_HEIGHTMAP_H

#define CONVERTISSEUR_HEIGHTMAP_H

#include "SommetTerrain.h"
#include "Terrain.h"
#include <vector>
#include <string>
#include <iostream>
#include <DirectXMath.h>
#include "toolsProjet.h"
#include <algorithm>
#include <fstream>

namespace PM3D {
   class ConvertisseurHeightMap {

   private:
      std::vector<SommetTerrain> sommets; // liste des sommets
      int dx = 1, dy = 1; // dimension en X et en Y (ecart entre 2 points)
      int nbColones = 0; // indique le nombre de points sur l'axe X
      int nbLignes = 0; // indique le nombre de points sur l'axe Y
      std::string heightMapPath;
      Terrain terrain;

   public:
      ConvertisseurHeightMap(std::string heightMapPath) : heightMapPath{ heightMapPath } {}; // Constructeur
      ConvertisseurHeightMap() : ConvertisseurHeightMap("./../Map/heightMap.txt") {} // Constructeur par defaut

      ~ConvertisseurHeightMap() = default; // Destructeur

      void lireFichierHeightMap();
      void construireTerrain(float echelleXY, float echelleZ);
      void calculerNormales();
      void construireIndex();
      void enregistrerTout();

      int getDx() {
         return dx;
      }
      int getDy() {
         return dy;
      }
      int getNbColones() {
         return nbColones;
      }
      int getNbLignes() {
         return nbLignes;
      }

      int getNbSommets() {
         return nbColones * nbLignes;
      }
      int getNbPolygones() {
         return (nbColones - 1) * (nbLignes - 1) * 2;
      }

   private:

      DirectX::XMFLOAT3 calculerNormale(int x, int y);
      
      float findAltitude(int x, int y) {
         return std::find(sommets.begin(), sommets.end(), SommetTerrain::SommetTerrain(x, y, 0.0f))->position.z;
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
      friend  std::ostream& operator<< (std::ostream& _stream, ConvertisseurHeightMap& const mc) {
         mc.afficherHeightMapPath(_stream);
         mc.afficherNbLigne(_stream);
         mc.afficherNbColonne(_stream);
         mc.afficherNbSommets(_stream);
         mc.afficherNbPolygone(_stream);
         mc.afficherSommetsXYZ(_stream);
         return _stream;
      }
   };
}
#endif // !CONVERTISSEUR_HEIGHTMAP_H
