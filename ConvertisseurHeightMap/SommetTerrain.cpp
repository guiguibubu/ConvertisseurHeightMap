#include "SommetTerrain.h"

namespace PM3D {
   // Definir l'organisation de notre sommet
   D3D11_INPUT_ELEMENT_DESC SommetTerrain::layout[] = {
      { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
      { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
   };

   UINT SommetTerrain::numElements = ARRAYSIZE(SommetTerrain::layout);
}