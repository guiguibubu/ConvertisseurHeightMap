#ifndef C_TERRAIN

#define C_TERRAIN

#include <vector>
#include <iostream>
#include "SommetTerrain.h"
#include "Sauvegarde.h"

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
      Terrain(int nbColonnes, int nbLignes, int nbPolygones, std::vector<SommetTerrain>& sommets) : nbColonnes{ nbColonnes }, nbLignes{ nbLignes }, nbPolygones{ nbPolygones }, sommets{ sommets } {};
      Terrain(Sauvegarde sauvegarde) : nbLignes{ sauvegarde.nbLignes }, nbColonnes{ sauvegarde.nbColonnes }, listeTriangle{ sauvegarde.listeTriangle }, pIndices{ sauvegarde.pIndices }, nbPolygones{ static_cast<int>(sauvegarde.pIndices.size()) / 3 } {};
      ~Terrain() = default;
   public:
      void initIndex();
      void initListeTriangle();
      std::vector<SommetTerrain> getListeTriangle();

      // Pour debugger
   public:
      void afficherNbLigne(std::ostream& stream);
      void afficherNbColonne(std::ostream& stream);
      void afficherNbPolygone(std::ostream& stream);
      void afficherListeTriangle(std::ostream& stream);
      void afficherPointeurIndices(std::ostream& stream);

   // Permet d'afficher l'objet dans un flux via '<<'
   friend  std::ostream& operator<< (std::ostream& _stream, Terrain& const mc) {
      mc.afficherNbLigne(_stream);
      mc.afficherNbColonne(_stream);
      mc.afficherNbPolygone(_stream);
      mc.afficherListeTriangle(_stream);
      mc.afficherPointeurIndices(_stream);
      return _stream;
   }

   };
};


#endif // !C_TERRAIN
