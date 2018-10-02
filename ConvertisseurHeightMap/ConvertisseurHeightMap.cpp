#include "ConvertisseurHeightMap.h"
#include "Sauvegarde.h"
#include <string>

namespace PM3D {
   void ConvertisseurHeightMap::lireFichierHeightMap() {

      std::ifstream in{ heightMapPath };

      int entierLu; // entier lu dans le fichier
      int indexLigne = 0;
      int indexColonne = 0;

      int i = 0;
      while (in >> entierLu) {
         // 1ere ligne correspond aux nombres de lignes
         if (i == 0) {
            nbLignes = entierLu;
         }
         // 2eme ligne correspond aux nombres de colonnes
         else if (i == 1) {
            nbColones = entierLu;
         }
         // On lit la hauteurs pour chaque sommet suivant l'axe des "x" croissant puis l'axe des "y" croissants
         else {
            indexColonne = (i - 2) % nbColones;
            indexLigne = (i - 2) / nbColones;

            sommets.push_back(SommetTerrain(indexColonne, indexLigne, entierLu));
         }
         i++;
      }
   }

   void ConvertisseurHeightMap::construireTerrain(float echelleXY, float echelleZ) {
      terrain = PM3D::Terrain::Terrain(getNbColones(), getNbLignes(), getNbPolygones(), sommets);
      terrain.initIndex();
   }

   void ConvertisseurHeightMap::construireIndex() {
      terrain.initListeTriangle();
   }

   void ConvertisseurHeightMap::calculerNormales() {
      for (SommetTerrain& sommet : sommets) {
         int x = sommet.position.x;
         int y = sommet.position.y;
         sommet.normal = calculerNormale(x, y);
     }
   }

   DirectX::XMFLOAT3 ConvertisseurHeightMap::calculerNormale(int x, int y) {
      DirectX::XMVECTOR n1;
      DirectX::XMVECTOR n2;
      DirectX::XMVECTOR n3;
      DirectX::XMVECTOR n4;

      DirectX::XMVECTOR v1;
      DirectX::XMVECTOR v2;
      DirectX::XMVECTOR v3;
      DirectX::XMVECTOR v4;

      n1 = n2 = n3 = n4 = DirectX::XMVectorSet(0, 0, 1, 0); // Le Z est le haut
      
      float z = findAltitude(x, y);
      if (y < nbLignes - 1) v1 = DirectX::XMVectorSet(0, dy, findAltitude(x, y+1) - z, 0);
      if (x < nbColones - 1) v2 = DirectX::XMVectorSet(dx, 0, findAltitude(x+1, y) - z, 0);
      if (y > 0) v3 = DirectX::XMVectorSet(0, -dy, findAltitude(x, y - 1) - z, 0);
      if (x > 0) v4 = DirectX::XMVectorSet(-dx, 0, findAltitude(x - 1, y) - z, 0);
      // les produits vectoriels
      if (y < nbLignes - 1 && x < nbColones - 1) n1 = DirectX::XMVector3Cross(v2, v1);
      if (y > 0 && x < nbColones - 1) n2 = DirectX::XMVector3Cross(v3, v2);
      if (y > 0 && x > 0) n3 = DirectX::XMVector3Cross(v4, v3);
      if (y < nbLignes - 1 && x > 0) n4 = DirectX::XMVector3Cross(v1, v4);
      
      using namespace DirectX;

      n1 = DirectX::XMVector3Normalize(n1 + n2 + n3 + n4);

      DirectX::XMFLOAT3 resultat;
      DirectX::XMStoreFloat3(&resultat, n1);
      return resultat;
   }

   void ConvertisseurHeightMap::enregistrerTout() {
      Sauvegarde sauvegarde = Sauvegarde::Sauvegarde(HEIGHTMAP_SAVEFILE_PATH_DEFAULT, dx, dy, nbColones, nbLignes, terrain.getListeTriangle(), terrain.pIndices);
      sauvegarde.save();
   }

   void ConvertisseurHeightMap::afficherSommetsXYZ(std::ostream& stream) {
      printIntoStream(stream, "Sommets lecture et calcul normales : ");
      for (SommetTerrain sommetTerrain : sommets) {
         printIntoStream(stream, "x = " + std::to_string(sommetTerrain.position.x) + " y = " + std::to_string(sommetTerrain.position.y) + " z = " + std::to_string(sommetTerrain.position.z) + " nx = " + std::to_string(sommetTerrain.normal.x) + " ny = " + std::to_string(sommetTerrain.normal.y) + " nz = " + std::to_string(sommetTerrain.normal.z));
      }
   }

   void ConvertisseurHeightMap::afficherHeightMapPath(std::ostream& stream) {
      printIntoStream(stream, "HeightMapPath : " + heightMapPath);
   }
   void ConvertisseurHeightMap::afficherNbLigne(std::ostream& stream) {
      printIntoStream(stream, "Nb Ligne : " + std::to_string(nbLignes));
   }
   void ConvertisseurHeightMap::afficherNbColonne(std::ostream& stream) {
      printIntoStream(stream, "Nb Colonne : " + std::to_string(nbColones));
   }
   void ConvertisseurHeightMap::afficherNbSommets(std::ostream& stream) {
      printIntoStream(stream, "Nb Sommet : " + std::to_string(getNbSommets()));
   }
   void ConvertisseurHeightMap::afficherNbPolygone(std::ostream& stream) {
      printIntoStream(stream, "Nb Polygone : " + std::to_string(getNbPolygones()));
   }
}