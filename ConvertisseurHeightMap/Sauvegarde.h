#ifndef SAUVEGARDE

#define SAUVEGARDE

#include <vector>
#include "SommetTerrain.h"
#include <bitset>

class Sauvegarde {

private:
   std::vector<PM3D::SommetTerrain> listeTriangle;
   std::vector<unsigned int> pIndices;
public:
   Sauvegarde() = default;
   ~Sauvegarde() = default;

   Sauvegarde(std::vector<PM3D::SommetTerrain> listeTriangle, std::vector<unsigned int> pIndices) : pIndices{ pIndices }, listeTriangle{ listeTriangle } {};

public:
   void save();
   void read(std::string savedFilePath);
private:
   std::bitset<192> convertSommetToBinary();
};

#endif // !SAUVEGARDE
