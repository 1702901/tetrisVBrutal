#ifndef SLIME_H
#define SLIME_H
#include "enemigo.h"
class slime
{
private:
	enemigo caracteristicas;
public:
	slime() { caracteristicas.setY(0); caracteristicas.setX(COLUMNESATAULER-1); };
	ColorFigura getColorValue() const { return SLIME; }
	int getX() const { return caracteristicas.getX(); };
	int getY() const { return caracteristicas.getY(); };
	void moverSlime() { caracteristicas.moverMonstreEndevant(); };
	void desMoverSlime() { caracteristicas.moverMonstreAtras(); };
};


#endif