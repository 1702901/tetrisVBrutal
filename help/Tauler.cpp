#include "Tauler.h"
ostream& operator<<(ostream& out, const Tauler& partida)
{

	string lineaMostrar;
	int colum = 0;
	int y;
	for (int x = 0; x < COLUMNESATAULER; x++)
	{
		lineaMostrar = "[";
		for (y = 0; y < FILESTAULER - 1; y++)
			lineaMostrar = lineaMostrar + to_string(partida.getPosition(x, y)) + ",";
		lineaMostrar = lineaMostrar + to_string(partida.getPosition(x, y)) + "]";
		out << lineaMostrar << endl;
	}
	return out;
}