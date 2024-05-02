#include "Joc.h"

Joc::Joc()
{
	// genera numeros random 
	// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 6) + 1;
	m_figura.cambiaFigura(randomNumber);
	m_figura.setX(FILESTAULER / 2);
	m_figura.setY(COLUMNESATAULER / 2);
	posarFigura();
	fiPartida = false;
}
// regenera la figura amb les mateixe coordenades x pero posa la y = 0 per possarla assobre
void Joc::novaFigura()
{
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 6) + 1;
	int lenghLine = m_figura.getLenghLine();
	m_figura.cambiaFigura(randomNumber);
	m_figura.setY(0);
	if (m_figura.getX() < 0)
		m_figura.setX(0);
	else
	{
		// posiciona la figura fins que no es surti del tauler
		while (m_figura.getLenghLine() + m_figura.getX() > FILESTAULER)
			m_figura.setX(m_figura.getX() - 1);

	}


	fiPartida = mirarSiHaColisionsFigura();

	if(!fiPartida)
		posarFigura();
}

int posCentroAEsquinaY(int pos)
{
	pos -= 1;
	return pos;
}

int posCentroAEsquinaX(int pos, const int tamany, int cuantitatDeGirs)
{
	if (tamany == 16)
	{
		if (cuantitatDeGirs == 3)
			pos -= 2;
		else
		{
			if (cuantitatDeGirs != 1)
				pos -= 1;
		}
	}
	else
		pos -= 1;
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
		// Cal tenir en compte que pensem que la esquina de tots es a la pos +1 +1 de la esquina excepte 
		// el cuadrat, sino es asi, si haura de cambiar la funcio posCentroAEsquina
		m_figura.setY(posCentroAEsquinaY(posY));
		m_figura.setX(posCentroAEsquinaX(posX, m_figura.getTamany(), cuantitatDeGirsHoraris));
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
		if (mirarSiHaColisionsFigura())
			cout << "Has perdut la partida" << endl;
		else
			posarFigura();
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
			if ((columna >= COLUMNESATAULER || fila >= FILESTAULER) && colorDeLaPos != COLOR_NEGRE)
				colisio = true;
			
            else
            {
				if (colorDeLaPos != COLOR_NEGRE && m_tauler.getPosition(columna, fila) != COLOR_NEGRE)
					colisio = true;
            	else
            	{
            		if ( (columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE)
            			colisio = true;
            	}
            }
			columna++;
		}
		fila++;
		columna = m_figura.getY();
	}
	return colisio;
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
	colisions = mirarSiHaColisionsFigura();
	// Refer figura en el mapa en cas de haber colisio
	if (colisions)
	{
		if (direccio == GIR_HORARI)
			m_figura.antiHorari();			
		else
			m_figura.girHorari();
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
	int maxValueLine = m_figura.getY() + m_figura.getLenghLine();
	// Como valor mas bajo solo comprovamos la linea 0
	// El caso es que hay figuras que su array puede salir, pero no la figura en si
	// Por tanto de ahi la existencia de este if
	fila = m_figura.getY();
	if (fila < 0)
		fila = 0;
	if (maxValueLine > MAX_COL)
		maxValueLine = MAX_COL;
	for(fila;fila < maxValueLine; fila++)
	{
		lineCompleta = true;
		columna = 0;
		while (lineCompleta && columna < FILESTAULER )
		{
			if (m_tauler.getPosition(fila, columna) == COLOR_NEGRE )
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
				for (int columnasEliminar = 0; columnasEliminar < FILESTAULER; columnasEliminar++)
					// filaEliminar - 1 per cargar el valor de la fila de sobre
					m_tauler.setPosition(columnasEliminar, filaEliminar, ColorFigura(m_tauler.getPosition(filaEliminar - 1, columnasEliminar)));
			}
			// Posem la linea superior en negra 
			for (int columnasEliminar = 0; columnasEliminar < FILESTAULER; columnasEliminar++)
				m_tauler.setPosition(columnasEliminar,0 , COLOR_NEGRE);
			filesEliminades++;
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
		novaFigura();
	}
	// Part on hem de mirar si hem de eliminar una linea o lineas etc
	else
		posarFigura();
	// entenem segons els nostres companys que sempre hem de posar la figura, sino es el cas eliminar
	// aquesta ´linea
	return filesEliminades;
}
int Joc::hardDrop()
{
	bool colisions = false;
	int filesEliminades = 0;
	while (!colisions)
	{
		borrarFigura();
		m_figura.setY(m_figura.getY() + 1);
		colisions = mirarSiHaColisionsFigura();
		if (colisions)
		{
			m_figura.setY(m_figura.getY() - 1);
			posarFigura();
			filesEliminades = eliminarLineasCompletesBaixada();
			novaFigura();
		}
		// Part on hem de mirar si hem de eliminar una linea o lineas etc
		else
			posarFigura();
	}
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
	m_figura.cambiaFigura(tipusFiguraNova);
}