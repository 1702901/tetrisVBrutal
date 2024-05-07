#ifndef SLIME_H
#define SLIME_H
#include "enemigo.h"
class Slime
{
private:
	enemigo m_caracteristicas;
	Figuras m_representacionTablero;
public:
	Slime() { m_representacionTablero.setY(FILESTAULER - 1); m_representacionTablero.setX(COLUMNESATAULER - 1); };
	void inicialitza() { m_representacionTablero.setY(FILESTAULER - 1); m_representacionTablero.setX(COLUMNESATAULER - 1); }
	ColorFigura getColorValue() const { return SLIME; }
	int getX() const { return m_representacionTablero.getX(); };
	int getY() const { return m_representacionTablero.getY(); };
	void setX(const int x) { m_representacionTablero.setX(x); };
	void setY(const int y) { m_representacionTablero.setY(y); };
	int getValuePos() const { return int(SLIME); };


};


#endif