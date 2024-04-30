#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h"
class Joc
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	bool fiPartida;
public:
	Joc();
	void novaFigura();
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
	bool getFiPartida()  const { return fiPartida; };
};

#endif