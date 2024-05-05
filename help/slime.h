#ifndef SLIME_H
#define SLIME_H
#include "enemigo.h"
class slime
{
private:
	enemigo m_caracteristicas;
	Figuras m_representacionTablero;
public:
	slime() { m_representacionTablero.setY(FILESTAULER - 1); m_representacionTablero.setX(COLUMNESATAULER - 1); };
	ColorFigura getColorValue() const { return SLIME; }
	int getX() const { return m_representacionTablero.getX(); };
	int getY() const { return m_representacionTablero.getY(); };
};


#endif