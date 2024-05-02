#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "struct.h"
class enemigo
{
private:
	// Columnes X // Files Y
	int posicion[DIMENSIONS];
	int tamany;
public:
	int getX() const { return posicion[0]; };
	void setX(const int x) { posicion[0] = x; }
	int getY() const { return posicion[1]; };
	void setY(const int y) { posicion[1] = y; }
	void moverMonstreEndevant() { posicion[0]--; };
	void moverMonstreAtras() { posicion[0]++; };

};


#endif