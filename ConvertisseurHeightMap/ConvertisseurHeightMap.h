#ifndef CONVERTISSEUR_HEIGHTMAP_H

#define CONVERTISSEUR_HEIGHTMAP_H

void LireFichierHeightMap();
void ConstruireTerrain(float echelleXY, float echelleZ);
void CalculerNormales();
void ConstruireIndex();
void EnregistrerTout();

#endif // !CONVERTISSEUR_HEIGHTMAP_H
