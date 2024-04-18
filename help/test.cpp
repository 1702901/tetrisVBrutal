#include "figura.h"
#include "test.h"
#include "Joc.h"

void mostrarCreacioFigures()
{
    //mostra com es generen correctement totes les figures 
    for (int figura = 0; figura < 7; figura++)
    {
        Figuras novaFigura(figura , 4);
        cout << novaFigura << endl;
    }
    system("PAUSE");
}

void mostrarGirAntiHorari()
{
    for (int i = FIGURA_O; i < NO_FIGURA; i++)
    {
        Figuras novaFigura(i, 4);
        cout << novaFigura << endl;
        const int ferNCops = 4;
        for (int y = 0; y < ferNCops; y++)
        {
            novaFigura.antiHorari();
            cout << novaFigura << endl;
        }
        system("PAUSE");
    }
}

void mostrarGirHorari()
{
    for (int i = FIGURA_O; i < NO_FIGURA; i++)
    {
        Figuras novaFigura(i, 4);
        cout << novaFigura << endl;
        const int ferNCops = 4;
        for (int y = 0; y < ferNCops; y++)
        {
            novaFigura.girHorari();
            cout << novaFigura << endl;
        }
        system("PAUSE");
    }
}

int main() 
{
    //mostrarCreacioFigures();
    //mostrarGirAntiHorari();
    //mostrarGirHorari();
    Joc nouJocTetris;
    nouJocTetris.inicialitza("archiuTest.txt");

    nouJocTetris.mostrarTualer();
    nouJocTetris.mostrarFigura();
    return 0;
}