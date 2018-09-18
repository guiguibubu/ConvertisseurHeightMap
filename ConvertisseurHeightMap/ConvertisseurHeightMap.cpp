
#include "ConvertisseurHeightMap.h"

int main() {

   LireFichierHeightMap();
   ConstruireTerrain(1.0f, 1.0f);
   CalculerNormales();
   ConstruireIndex();
   EnregistrerTout();

   return 0;
}