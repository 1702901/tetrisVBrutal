#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	ColorFigura color;
	int value;
	fitxer.open(nomFitxer);
	int tipusFigura, posX, posY, cuantitatDeGirsHoraris;
	// Columnes X // Files Y
	if (fitxer.is_open())
	{
		fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;
		m_figura.setY(posY);
		m_figura.setX(posX);
		m_figura.cambiaFigura(tipusFigura);
		for (int i = 0; i < cuantitatDeGirsHoraris; i++)
			m_figura.girHorari();
		for (int x = 0; x < COLUMNESATAULER; x++)
		{
			for (int y = 0; y < FILESTAULER; y++)
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
