#include "Joc.h"

int posCentroAEsquina(int pos,const int tamany, bool esX)
{
	
	switch (tamany)
	{
	case 9:
		pos -= 1;
		break;
	case 16:
		if (esX)
		{
			pos -= 2;
		}
		else
		{
			pos -= 1;
		}
		break;
	default:
	
		break;
	}
	return pos;
}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	ColorFigura color;
	int value;
	fitxer.open(nomFitxer);
	int tipusFigura, posX, posY, cuantitatDeGirsHoraris;
	// Columnes Y// Files X
	if (fitxer.is_open())
	{
		fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;
		m_figura.cambiaFigura(tipusFigura - 1);
		m_figura.setY(posCentroAEsquina(posY, m_figura.getTamany(), false));
		m_figura.setX(posCentroAEsquina(posX, m_figura.getTamany(), true));
		for (int i = 0; i < cuantitatDeGirsHoraris; i++)
			m_figura.girHorari();
		for (int y = 0; y < COLUMNESATAULER; y++)
		{
			for (int x = 0; x < FILESTAULER; x++)
			{
				fitxer >> value;
				color = ColorFigura(value);
				m_tauler.setPosition(x,y,color);
			}
		}
	}
	else
		cout << "Error al obrir l'arxiu";



	fitxer.close();
}


void Joc::mostrarTualer()
{
	cout << m_tauler;
}

void Joc::mostrarFigura()
{
	cout << m_figura;
}

void Joc::borrarFigura()
{
	
	for (int fila = m_figura.getY(); fila < m_figura.getY() + m_figura.getLenghLine(); fila++)
	{
		for (int columna = m_figura.getX(); columna < m_figura.getX() + m_figura.getLenghLine(); columna++)
		{
			cout << endl << "Ques es esto" << fila - m_figura.getY() << endl;
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
				m_tauler.setPosition(columna, fila, COLOR_NEGRE);
		}
	}
}

void Joc::posarFigura()
{
	for (int fila = m_figura.getY(); fila < m_figura.getY() + m_figura.getLenghLine(); fila++)
	{
		for (int columna = m_figura.getX(); columna < m_figura.getX() + m_figura.getLenghLine(); columna++)
		{
			cout << endl << "Ques es esto" << fila - m_figura.getY() << endl;
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
				m_tauler.setPosition(columna, fila, ColorFigura(m_figura.getColor()));
		}
	}
}


bool Joc::giraFigura(DireccioGir direccio)
{
	// presuposem que hem posat un codi al inici de crear la figura
	bool EsPotGirar = true;
	// Borrar figura del mapa


	// Girar figura per veure com es posaria al tauler 
	if (direccio == GIR_HORARI)
	{
		m_figura.girHorari();

	}
	else
	{
		m_figura.antiHorari();
	}
	// Funcio per mirar si hi ha colisions 
	

	if (!EsPotGirar)
	{
		if (direccio == GIR_HORARI)
		{
			m_figura.antiHorari();			
		}
		else
		{
			m_figura.girHorari();

		}
		// Refer figura en el mapa
	}
	else
	{
		// funcio que posa la figura
	}

	return EsPotGirar;
};
