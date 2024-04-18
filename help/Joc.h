#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "test.h"
#include "Tauler.h"
class Joc
{
private:
	Tauler m_tauler;
	Figuras m_figura;
public:
	void inicialitza(const string& nomFitxer);
	void mostrarTualer();
	void mostrarFigura();
	//bool giraFigura(DireccioGir direccio);
	//bool mouFigura(int dirX);
	//int baixaFigura();
	//void escriuTauler(const string& nomFitxer);
};




#endif