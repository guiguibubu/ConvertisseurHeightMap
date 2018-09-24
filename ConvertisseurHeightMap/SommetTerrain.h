#ifndef C_SOMMET_TERRAIN_H

#define C_SOMMET_TERRAIN_H

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

namespace PM3D {
   class SommetTerrain {

   public:
      static UINT numElements;
      static D3D11_INPUT_ELEMENT_DESC layout[];

   public:
      DirectX::XMFLOAT3 position;
      DirectX::XMFLOAT3 normal;

   public:
      // Constructeur par defaut
      SommetTerrain() {
         SommetTerrain(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
      };
      // Constructeur
      SommetTerrain(const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& normal) : position{ position }, normal{ normal } {

      };
      // Constructeur
      SommetTerrain(float x, float y, float z) : position{ DirectX::XMFLOAT3(x,y,z) }, normal{ DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f) } {

      };
      ~SommetTerrain() = default; // Destructeur

      //on redefini 
      bool operator== (SommetTerrain const &sommet) const {
         return position.x == sommet.position.x 
            && position.y == sommet.position.y;
      }
   };
}
#endif // !C_SOMMET_TERRAIN_H
