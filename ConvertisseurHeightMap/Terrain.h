#ifndef C_TERRAIN

#define C_TERRAIN

#include <vector>
#include "SommetTerrain.h"

namespace PM3D {
   class Terrain {

   private:
      int nbPolygones;
      int nbColonnes;
      int nbLignes;
      std::vector<SommetTerrain> sommets; // liste des sommets
      std::vector<SommetTerrain> listeTriangle;
   public:
      std::vector<unsigned int> pIndices;

   public:
      Terrain() = default;
      Terrain(int nbColonnes, int nbLignes, int nbPolygones, std::vector<SommetTerrain> sommets) : nbColonnes{ nbColonnes }, nbLignes{ nbLignes  }, nbPolygones{ nbPolygones }, sommets{ sommets } {};

      ~Terrain() = default;
   public:
      void initIndex();
      void initListeTriangle();
      std::vector<SommetTerrain> getListeTriangle();

   };
}

#endif // !C_TERRAIN
