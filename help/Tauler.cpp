#include "Tauler.h"
ostream& operator<<(ostream& out, const Tauler& partida)
{

	string lineaMostrar;
	int colum = 0;
	int y;
	for (int x = 0; x < FILESTAULER; x++)
	{
		lineaMostrar = "[";
		for (y = 0; y < COLUMNESATAULER - 1; y++)
		{
			if(partida.getPosition(x, y) == COLOR_NEGRE)
				lineaMostrar = lineaMostrar + "  ";
			else
				lineaMostrar = lineaMostrar + to_string(partida.getPosition(x, y)) + " ";
		}
		if (partida.getPosition(x, y) == COLOR_NEGRE)
			lineaMostrar = lineaMostrar + "  ";
		else
			lineaMostrar = lineaMostrar + to_string(partida.getPosition(x, y)) + " ";

		lineaMostrar = lineaMostrar + "]";
		out << lineaMostrar << endl;
	}
	return out;
}

Tauler::Tauler()
{
	for (int j = 0; j < COLUMNESATAULER ; j++)
	{
		for(int i = 0; i < FILESTAULER; i++)
		{
			taulerJoc[j][i] = COLOR_NEGRE;
		}
	}
	ordreGirs = 0;
}