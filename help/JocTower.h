#ifndef TAULER_TOWER_H
#define TAULER_TOWER_H
#include "Figura.h"
#include "Tauler.h"

class JocTower
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	bool fiPartida;
public:
	JocTower();
	void novaFigura();
	void mostrarTualer();
	void mostrarFigura();
	bool giraFigura(DireccioGir direccio);
	void borrarFigura();
	void posarFigura();
	bool mirarSiHaColisionsFigura();
	bool mouFigura(int dirX);
	int baixaFigura();
	int eliminarLineasCompletesBaixada();
	void escriuTauler(const string& nomFitxer);
	void inicialitzaFigura(const int tipusFiguraNova);
	bool getFiPartida()  const { return fiPartida; };
	int hardDrop();
};



#endif