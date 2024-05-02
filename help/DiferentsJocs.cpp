#include "DiferentsJocs.h"

void tetris()
{
	// Get the current time as a time_point
	chrono::time_point<std::chrono::steady_clock, std::chrono::duration<_int64, std::ratio<1, 10000000000>>> now = std::chrono::high_resolution_clock::now();
	// Convert the time_point to a duration since the epoch in microseconds
	auto duration = now.time_since_epoch();
	// Cast the duration to microseconds 
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
	// Creates microsecondsEnd
	auto microsecondsEnd = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
	// _____________________________________________________________________________________________________________
	// COMIENZA EL CODIGO DEL JUEGO
	char tecla;
	Joc tetris;
	tetris.mostrarTualer();
	while (!tetris.getFiPartida())
	{
		now = std::chrono::high_resolution_clock::now();
		duration = now.time_since_epoch();
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
		while (microsecondsEnd - microseconds < 1000000)
		{
			now = std::chrono::high_resolution_clock::now();
			duration = now.time_since_epoch();
			microsecondsEnd = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
			if (_kbhit())
			{
				// aqui se guarda el valor pulsado 
				tecla = _getch();
				// segun la tecla pulsada hacemos x accion
				switch (tecla)
				{
				case 'l':
					tetris.giraFigura(GIR_HORARI);
					break;
				case 'j':
					tetris.giraFigura(GIR_ANTI_HORARI);
					break;
				case 'a':
					tetris.mouFigura(-1);
					break;
				case 'd':
					tetris.mouFigura(+1);
					break;
				case 's':
					tetris.hardDrop();
					break;
				default:
					break;
				}
				system("cls");
				tetris.mostrarTualer();
			}
		}
		tetris.baixaFigura();
		system("cls");
		tetris.mostrarTualer();
		// despres de esperar les tecles baixa la figura
		// comprueba que no se ha perdido la partida
	}
	// no se hasta darle a q 
	cout << "\nFi de la partida dona a q per sortir";
	while (_getch() != 'q')
	{

	}


	// COMENTANT COM FUNCIONA LA DETECCIO DE TECLES
	/*
	// Output the current time in microseconds
	// LLegir tecla
	// kbhit hace que no entre a menos que se presione una tecla
		if (_kbhit())
		{
			// aqui se guarda el valor pulsado
			tecla = _getch();
			cout << tecla << endl;
		}
	*/
}


void towerTetris()
{

}