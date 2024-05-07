#include "JocTower.h"

JocTower::JocTower()
{
	// genera numeros random 
	// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 6) + 1;
	m_figura.cambiaFigura(randomNumber);
	m_figura.setX(COLUMNESATAULER / 2);
	m_figura.setY(FILESTAULER / 2);
	posarFigura();
	fiPartida = false;
	vida = MAX_VIDA_MAGO;
}
// regenera la figura amb les mateixe coordenades x pero posa la y = 0 per possarla assobre
void JocTower::novaFigura()
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
		while (m_figura.getLenghLine() + m_figura.getX() > COLUMNESATAULER)
			m_figura.setX(m_figura.getX() - 1);
	}

	fiPartida = mirarSiHaColisionsFigura();

	if (!fiPartida)
		posarFigura();
}



void JocTower::mostrarTualer()
{
	cout << m_tauler;
}

void JocTower::mostrarFigura()
{
	cout << m_figura;
}

void JocTower::borrarFigura()
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

void JocTower::posarFigura()
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

void JocTower::posarFiguraHardDrop()
{
	for (int fila = m_figura.getY(); fila < m_figura.getY() + m_figura.getLenghLine(); fila++)
	{
		for (int columna = m_figura.getX(); columna < m_figura.getX() + m_figura.getLenghLine(); columna++)
		{
			
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
			{
				// > perque aixi tot monstre eliminara una part de la figura al caura 
				if (ColorFigura(m_tauler.getPosition(fila, columna) > COLOR_NEGRE))
					m_figura.setValuePos0(columna, fila);
				else
					m_tauler.setPosition(columna, fila, ColorFigura(m_figura.getColor()));
			}
		}
	}
}


bool JocTower::mirarSiHaColisionsFigura()
{
	bool colisio = false;
	int fila = m_figura.getX(), columna = m_figura.getY();
	ColorFigura colorDeLaPos;
	while (!colisio && fila < m_figura.getX() + m_figura.getLenghLine())
	{
		while (!colisio && columna < m_figura.getY() + m_figura.getLenghLine())
		{
			colorDeLaPos = ColorFigura(m_figura.getValuePos(fila - m_figura.getX(), columna - m_figura.getY()));
			if ((columna >= FILESTAULER || fila >= COLUMNESATAULER) && colorDeLaPos != COLOR_NEGRE)
				colisio = true;

			else
			{
				// != perque tots els superiors son elements no eliminables ( slimes i demes, mirar srtuct per aixo ) ya  que nomes se eliminen quan 
				// es el moviment de baixada
				if (colorDeLaPos != COLOR_NEGRE && m_tauler.getPosition(columna, fila) != COLOR_NEGRE) 
					colisio = true;
				else
				{
					if ((columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE)
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

bool JocTower::mirarSiHaColisionsFiguraBaixada()
{

	bool colisio = false;
	int fila = m_figura.getX(), columna = m_figura.getY();
	ColorFigura colorDeLaPos;
	while (!colisio && fila < m_figura.getX() + m_figura.getLenghLine())
	{
		while (!colisio && columna < m_figura.getY() + m_figura.getLenghLine())
		{
			colorDeLaPos = ColorFigura(m_figura.getValuePos(fila - m_figura.getX(), columna - m_figura.getY()));
			if ((columna >= FILESTAULER || fila >= COLUMNESATAULER) && colorDeLaPos != COLOR_NEGRE)
				colisio = true;

			else
			{
				// perque tots els elements que surtin de l'interval es poden eliminar de baixasa
				if (colorDeLaPos != COLOR_NEGRE && ( m_tauler.getPosition(columna, fila) > COLOR_NEGRE ) && (m_tauler.getPosition(columna, fila) < SLIME))
					colisio = true;
				else
				{
					if ((columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE)
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

bool JocTower::giraFigura(DireccioGir direccio)
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




bool JocTower::mouFigura(int dirX)
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


int JocTower::eliminarLineasCompletesBaixada()
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
	if (maxValueLine > MAX_FILA)
		maxValueLine = MAX_FILA;
	for (fila; fila < maxValueLine; fila++)
	{
		lineCompleta = true;
		columna = 0;
		while (lineCompleta&& columna < COLUMNESATAULER)
		{
			if (m_tauler.getPosition(fila, columna) == COLOR_NEGRE)
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
					// filaEliminar - 1 per cargar el valor de la fila de sobre
					m_tauler.setPosition(columnasEliminar, filaEliminar, ColorFigura(m_tauler.getPosition(filaEliminar - 1, columnasEliminar)));
			}
			// Posem la linea superior en negra 
			for (int columnasEliminar = 0; columnasEliminar < COLUMNESATAULER; columnasEliminar++)
				m_tauler.setPosition(columnasEliminar, 0, COLOR_NEGRE);
			filesEliminades++;
		}
	}
	return filesEliminades;
}


int JocTower::baixaFigura()
{
	// Part on es mira si hi ha colisions
	bool colisions;
	int filesEliminades = 0;
	borrarFigura();
	m_figura.setY(m_figura.getY() + 1);
	colisions = mirarSiHaColisionsFiguraBaixada();
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
int JocTower::hardDrop()
{
	int filesEliminades = 0;
	// baixa la figura fins que doni colisio
	borrarFigura();
	while (!mirarSiHaColisionsFiguraBaixada())
	{
		posarFigura();
		borrarFigura();
		m_figura.setY(m_figura.getY() + 1);
	}
	// desfa el moviment que causa la colisio 
	m_figura.setY(m_figura.getY() - 1);
	// posa la figura on no fa colisio i fa el procediment vist a baixaFigura
	posarFigura(); 
	filesEliminades = eliminarLineasCompletesBaixada();
	novaFigura();
	return filesEliminades;
}


void JocTower::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	// Columnes Y// Files X
	if (fitxer.is_open())
	{
		string lineaMostrar;
		int colum = 0;
		int y;
		for (int x = 0; x < FILESTAULER; x++)
		{
			lineaMostrar = "";
			for (y = 0; y < COLUMNESATAULER - 1; y++)
				lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y)) + " ";
			lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y));
			fitxer << lineaMostrar << endl;
		}
	}
	else
		cout << "Error al obrir l'arxiu";
	fitxer.close();
}

void JocTower::inicialitzaFigura(const int tipusFiguraNova)
{
	m_figura.cambiaFigura(tipusFiguraNova);
}

void JocTower::inicialitzaSlime(Slime& slimeABorrar)
{
	slimeABorrar.inicialitza();
}
void JocTower::borrarSlime(Slime& slimeABorrar)
{
	m_tauler.setPosition(slimeABorrar.getX(), slimeABorrar.getY(), COLOR_NEGRE);
}
void JocTower::posarSlime(Slime& slimeAPossar)
{
	m_tauler.setPosition(slimeAPossar.getX(), slimeAPossar.getY(), SLIME);
}

bool JocTower::mirarSiHaColisionsSlime(Slime& slimeAMoure)
{
	bool colisio = false;
	int fila = slimeAMoure.getX(), columna = slimeAMoure.getY();
	ColorFigura colorDeLaPos;
	while (!colisio && fila < slimeAMoure.getX() + TAMANY_SLIME)
	{
		while (!colisio && columna < m_figura.getY() + TAMANY_SLIME)
		{
			colorDeLaPos = ColorFigura(slimeAMoure.getValuePos());
			if ((columna >= FILESTAULER || fila >= COLUMNESATAULER) && colorDeLaPos != COLOR_NEGRE)
				colisio = true;
			else
			{
				// != perque tots els superiors son elements no eliminables ( slimes i demes, mirar srtuct per aixo ) ya  que nomes se eliminen quan 
				// es el moviment de baixada
				if (colorDeLaPos != COLOR_NEGRE && m_tauler.getPosition(columna, fila) != SLIME)
					colisio = true;
				else
				{
					if ((columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE)
						colisio = true;
				}
			}
			columna++;
		}
		fila++;
		columna = slimeAMoure.getY();
	}
	return colisio;
};

bool JocTower::mouSlime(int dirX, Slime& slimeAMoure)
{
	bool colisions = mirarSiHaColisionsSlime(slimeAMoure);
	if (colisions)
	{
		slimeAMoure.inicialitza();
		posarSlime(slimeAMoure);
	}
	else
	{
		borrarSlime(slimeAMoure);
		if (slimeAMoure.getX() + dirX < 0)
		{
			slimeAMoure.setX(COLUMNESATAULER - 1);
			vida--;
			if (vida == 0)
			{
				fiPartida = true;
			}
		}
		else
		{
			slimeAMoure.setX(slimeAMoure.getX() + dirX);
		}
		posarSlime(slimeAMoure);
	}
	
	return !colisions;
}