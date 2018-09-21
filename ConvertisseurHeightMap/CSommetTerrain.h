#ifndef C_SOMMET_TERRAIN_H

#define C_SOMMET_TERRAIN_H

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

class CSommetTerrain {

public:
   static UINT numElements;
   static D3D11_INPUT_ELEMENT_DESC layout[];

private:
   DirectX::XMFLOAT3 position;
   DirectX::XMFLOAT3 normal;

// methodes pour le debuggage
public:
   float getX() {
      return position.x;
   }
   float getY() {
      return position.y;
   }
   float getZ() {
      return position.z;
   }

   float getN1() {
      return normal.x;
   }
   float getN2() {
      return normal.y;
   }
   float getN3() {
      return normal.z;
   }

public:
   // Constructeur par defaut
   CSommetTerrain() {
      CSommetTerrain(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
   };
   // Constructeur
   CSommetTerrain(const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& normal) : position{ position }, normal{ normal } {

   }; 
   // Constructeur
   CSommetTerrain(float x, float y, float z) : position{ DirectX::XMFLOAT3(x,y,z) }, normal{ DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f) } {

   };
   ~CSommetTerrain() = default; // Destructeur

};
#endif // !C_SOMMET_TERRAIN_H
