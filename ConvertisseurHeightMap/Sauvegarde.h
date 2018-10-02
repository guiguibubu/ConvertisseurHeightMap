#ifndef SAUVEGARDE

#define SAUVEGARDE

#include <vector>
#include "SommetTerrain.h"
#include <bitset>

class Sauvegarde {

public:
   std::string saveFilePath;
   int dx = 1, dy = 1; // dimension en X et en Y (ecart entre 2 points)
   int nbColonnes = 0; // indique le nombre de points sur l'axe X
   int nbLignes = 0; // indique le nombre de points sur l'axe Y
   std::vector<PM3D::SommetTerrain> listeTriangle;
   std::vector<unsigned int> pIndices;
public:
   Sauvegarde() = default;
   ~Sauvegarde() = default;

   Sauvegarde(std::string saveFilePath, int dx, int dy, int nbColones, int nbLignes, std::vector<PM3D::SommetTerrain> listeTriangle, std::vector<unsigned int> pIndices) : saveFilePath{ saveFilePath }, dx{ dx }, dy{ dy }, nbColonnes { nbColones }, nbLignes{ nbLignes }, pIndices{ pIndices }, listeTriangle{ listeTriangle } {};
   Sauvegarde(std::string saveFilePath) : Sauvegarde(saveFilePath, 1, 1, 0, 0, std::vector<PM3D::SommetTerrain>::vector(), std::vector<unsigned int>::vector()) {};
public:
   void save();
   void read();
private:
   void saveLigneColonneDxDy(std::ostream& stream);
   void saveSommet(std::ostream& stream, PM3D::SommetTerrain sommet);
   void saveIndice(std::ostream& stream, unsigned int indice);

   void readLigneColonneDxDy(std::istream& stream);
   PM3D::SommetTerrain readSommet(std::istream& stream);
   unsigned int readIndice(std::istream& stream);

};

#endif // !SAUVEGARDE
