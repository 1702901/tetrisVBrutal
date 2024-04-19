#include "Joc.h"

int posCentroAEsquina(int pos,const int tamany, bool esX, int cuantitatDeGirs)
{
	
	switch (tamany)
	{
	case 9:
		pos -= 1;
		break;
	case 16:
		if (esX)
		{
			switch (cuantitatDeGirs)
			{
			case 0:
				pos -= 2;
				break;
			case 1:
				pos -= 2;
				break;
			case 2:
				pos -= 1;
				break;
			case 3:
				pos -= 2;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (cuantitatDeGirs)
			{
			case 0:
				pos -= 1;
				break;
			case 1:
				pos -= 2;
				break;
			case 2:
				pos -= 1;
				break;
			case 3:
				pos -= 1;
				break;
			default:
				break;
			}
		}
		break;
	default:
	
		break;
	}
	return pos;
}

void Joc::inicialitza(const string& nomFitxer)
{
	m_cuantitatGirs = 0;
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
		// Cal tenir en compte que pensem que la esquina de tots es a la pos +1 +1 de la esquina excepte 
		// el cuadrat, sino es asi, si haura de cambiar la funcio posCentroAEsquina
		m_figura.setY(posCentroAEsquina(posY, m_figura.getTamany(), false, cuantitatDeGirsHoraris));
		m_figura.setX(posCentroAEsquina(posX, m_figura.getTamany(), true, cuantitatDeGirsHoraris));
		m_cuantitatGirs = cuantitatDeGirsHoraris;
		cout << m_figura << endl;
		for (int i = 0; i < cuantitatDeGirsHoraris; i++)
		{
			m_figura.girHorari();
			cout << m_figura << endl;

		}
		for (int y = 0; y < COLUMNESATAULER; y++)
		{
			for (int x = 0; x < FILESTAULER; x++)
			{
				fitxer >> value;
				color = ColorFigura(value);
				m_tauler.setPosition(x,y,color);
			}
		}
		if (mirarSiHaColisionsFigura())
		{
			cout << "Has perdut la partida" << endl;
		}
		else
		{
			posarFigura();
		}
		cout << m_figura.getX() << endl;

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
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
				m_tauler.setPosition(columna, fila, ColorFigura(m_figura.getColor()));
		}
	}
}

bool Joc::mirarSiHaColisionsFigura()
{
	bool colisio = false;
	int fila = m_figura.getX(), columna = m_figura.getY();
	ColorFigura colorDeLaPos;
	while (!colisio && fila < m_figura.getX() + m_figura.getLenghLine())
	{
		while (!colisio && columna < m_figura.getY() + m_figura.getLenghLine())
		{
			colorDeLaPos = ColorFigura(m_figura.getValuePos(fila - m_figura.getX(), columna - m_figura.getY()));
			if ((colorDeLaPos != COLOR_NEGRE && m_tauler.getPosition(columna, fila) != COLOR_NEGRE ) || 
				((columna > COLUMNESATAULER || fila > FILESTAULER) &&  colorDeLaPos != COLOR_NEGRE) || 
				((columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE) )
				colisio = true;
			columna++;
		}
		fila++;
		columna = m_figura.getY();
	}
	return colisio;
}

void Joc::desGirarRecta(DireccioGir direccio)
{
	switch (m_cuantitatGirs)
	{
	case 0:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setY(m_figura.getY() + 1);
		else
			m_figura.setX(m_figura.getX() + 1);
		break;
	case 1:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setX(m_figura.getX() + 1);
		else
			m_figura.setY(m_figura.getY() - 1);

		break;
	case 2:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setY(m_figura.getY() - 1);
		else
			m_figura.setX(m_figura.getX() - 1);
		break;
	case 3:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setX(m_figura.getX() - 1);
		else
			m_figura.setY(m_figura.getY() + 1);
		break;
	default:
		cout << endl << "ERRRRROOORRRRR, la variable m_cuantitatGirs es mes gran del degur " << endl;
		break;
	}
	
}

void Joc::girarRecta(DireccioGir direccio)
{
	
	switch (m_cuantitatGirs)
	{
	case 0:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setY(m_figura.getY() - 1);
		else
			m_figura.setX(m_figura.getX() - 1);
		break;
	case 1:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setX(m_figura.getX() - 1);
		else
			m_figura.setY(m_figura.getY() + 1);

		break;
	case 2:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setY(m_figura.getY() + 1);
		else
			m_figura.setX(m_figura.getX() + 1);
		break;
	case 3:
		if (direccio == GIR_ANTI_HORARI)
			m_figura.setX(m_figura.getX() + 1);
		else
			m_figura.setY(m_figura.getY() - 1);
		break;
	default:
		cout << endl << "ERRRRROOORRRRR, la variable m_cuantitatGirs es mes gran del degur " << endl;
		break;
	}
}


bool Joc::giraFigura(DireccioGir direccio)
{
	// presuposem que hem posat un codi al inici de crear la figura
	bool colisions;
	// Borrar figura del mapa
	borrarFigura();
	// Girar figura per veure com es posaria al tauler 
	if (direccio == GIR_HORARI)
		m_figura.girHorari();
	else
		m_figura.antiHorari();
	if (m_figura.getTamany() == 16)
		girarRecta(direccio);

	colisions = mirarSiHaColisionsFigura();
	// Refer figura en el mapa en cas de haber colisio
	if (colisions)
	{
		if (m_figura.getTamany() == 16)
			desGirarRecta(direccio);
		if (direccio == GIR_HORARI)
			m_figura.antiHorari();			
		else
			m_figura.girHorari();
	}
	// per guardar cuantitat de girs unicament per el cas del palet
	else
	{
		if (direccio == GIR_HORARI)
		{
			m_cuantitatGirs++;
			if (m_cuantitatGirs > MAX_GIRS)
				m_cuantitatGirs = 0;
		}
		else
		{
			m_cuantitatGirs--;
			if (m_cuantitatGirs < 0)
				m_cuantitatGirs = 3;
		}
	}
	// Posar la figura cuan sabem que es pot girar
	posarFigura();
	return !colisions;
};




bool Joc::mouFigura(int dirX)
{
	bool colisions;
	borrarFigura();
	m_figura.setX(m_figura.getX() + dirX);
	colisions = mirarSiHaColisionsFigura();
	if (colisions)
		m_figura.setX(m_figura.getX() - dirX);
	posarFigura();
	return !colisions;
}

int Joc::eliminarLineasCompletesBaixada()
{
	bool lineCompleta;
	int columna, fila;
	int filesEliminades = 0;
	// Como valor mas bajo solo comprovamos la linea 0
	// El caso es que hay figuras que su array puede salir, pero no la figura en si
	// Por tanto de ahi la existencia de este if
	fila = m_figura.getY() - m_figura.getLenghLine();
	if (fila < 0)
		fila = 0;
	for(fila;fila < m_figura.getY(); fila++)
	{
		lineCompleta = true;
		columna = 0;
		while (lineCompleta && columna < COLUMNESATAULER)
		{
			if (m_tauler.getPosition(columna, fila) == COLOR_NEGRE )
				lineCompleta = false;
			columna++;
		}
		if (lineCompleta)
		{
			// -1 ja que l'ultima el seu valor es tot negre
			// el que fem es posar las dades de la fila superior de forma que es borrin unicament les
			// dades de la fila que volem eliminar
			for (int filaEliminar = fila; filaEliminar > 0; filaEliminar--)
			{
				for (int columnasEliminar = 0; columnasEliminar < COLUMNESATAULER; columnasEliminar++)
					m_tauler.setPosition(columnasEliminar, filaEliminar, ColorFigura(m_tauler.getPosition(columnasEliminar, filaEliminar - 1)));
			}
			// Posem la linea superior en negra 
			for (int columnasEliminar = 0; columnasEliminar < COLUMNESATAULER; columnasEliminar++)
				m_tauler.setPosition(columnasEliminar, 0, COLOR_NEGRE);
			filesEliminades++;
			// ho sento pero ho he de fer per poder fer curt l'algorisme ja que al elminar em de baixar el punter un -1
			fila--;
		}
	}
	return filesEliminades;
}


int Joc::baixaFigura()
{
	// Part on es mira si hi ha colisions
	bool colisions;
	int filesEliminades = 0;
	
	borrarFigura();
	m_figura.setY(m_figura.getY() + 1);
	colisions = mirarSiHaColisionsFigura();
	if (colisions)
	{
		m_figura.setY(m_figura.getY() - 1);
		posarFigura();
		filesEliminades = eliminarLineasCompletesBaixada();
	}
	// Part on hem de mirar si hem de eliminar una linea o lineas etc
	else
		posarFigura();
	// entenem segons els nostres companys que sempre hem de posar la figura, sino es el cas eliminar
	// aquesta ´linea
	return filesEliminades;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	// Columnes Y// Files X
	if (fitxer.is_open())
	{
		
		string lineaMostrar;
		int colum = 0;
		int y;
		
		for (int x = 0; x < COLUMNESATAULER; x++)
		{
			lineaMostrar = "";
			for (y = 0; y < FILESTAULER - 1; y++)
				lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y)) + " ";
			lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y));
			fitxer << lineaMostrar << endl;
		}
	}
	else
		cout << "Error al obrir l'arxiu";
	fitxer.close();
}

void Joc::inicialitzaFigura(const int tipusFiguraNova)
{
	m_cuantitatGirs = 0;
	m_figura.cambiaFigura(tipusFiguraNova);
}