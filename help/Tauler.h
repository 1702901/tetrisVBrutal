#ifndef TAULER_H
#define TAULER_H
#include "figura.h"
#include "test.h"
class Tauler
{
private:
	ColorFigura taulerJoc[COLUMNESATAULER][FILESTAULER];
	int ordreGirs;
public:
	void setPosition(const int posX, const int posY, const ColorFigura valueColor) { taulerJoc[posX][posY] = valueColor; };
	int getPosition(const int posX, const int posY) const { return int(taulerJoc[posX][posY]) ; };
};

ostream& operator<<(ostream& out, const Tauler& partida);


#endif
