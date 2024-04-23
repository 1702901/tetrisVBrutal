#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h"
class Joc
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	int m_cuantitatGirs;
public:
	void inicialitza(const string& nomFitxer);
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
	void girarRecta(DireccioGir direccio);
	void desGirarRecta(DireccioGir direccio);
};

#endif