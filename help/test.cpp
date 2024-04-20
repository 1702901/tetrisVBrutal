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

void ferTestLlegirArchiu (const string& nomArchiu)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomArchiu);
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.mostrarFigura();
}


void testPosarFigura(const string& nomArchiu)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomArchiu);
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.mostrarFigura();
    cout << endl << endl;
    nouJocTetris.posarFigura();
    cout << endl << endl;
    nouJocTetris.mostrarTualer();
    cout << endl << endl;
    nouJocTetris.mostrarFigura();
    cout << endl << endl;
}

void testEliminarFigura(const string& nomArchiu)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomArchiu);
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.mostrarFigura();
    cout << endl << endl;
    nouJocTetris.borrarFigura();
    cout << endl << endl;
    nouJocTetris.mostrarTualer();
    cout << endl << endl;
}

void testGirarFigura(const string& nomArchiu)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomArchiu);
    nouJocTetris.mostrarTualer();
    cout << endl << endl;
    nouJocTetris.mouFigura(-1);
    cout << endl << endl;
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.giraFigura(GIR_ANTI_HORARI);
    cout << endl << endl;
    nouJocTetris.mostrarTualer();
}


// Falta fer test d'aixo
//bool mouFigura(int dirX);
//int baixaFigura();
//int eliminarLineasCompletesBaixada();
// 
// 


void escriuTaulerTest(const string& nomFitxerLlegir ,const string& nomFitxerEscriure) 
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomFitxerLlegir);
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.escriuTauler(nomFitxerEscriure);
}

void baixaFigura(const string& nomFitxerLlegir)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomFitxerLlegir);
    nouJocTetris.mostrarTualer();
    nouJocTetris.baixaFigura();
    cout << endl;
    nouJocTetris.mostrarTualer();
    cout << endl;
}

void mouFigura(const string& nomFitxerLlegir)
{
    Joc nouJocTetris;
    nouJocTetris.inicialitza(nomFitxerLlegir);

    nouJocTetris.mostrarFigura();
    cout << endl;

    nouJocTetris.mostrarTualer();

    nouJocTetris.mouFigura(1);
    cout << endl;
    nouJocTetris.mostrarTualer();
    cout << endl;
    nouJocTetris.baixaFigura();

    cout << endl;
    nouJocTetris.mostrarTualer();
    cout << endl;
    cout << endl;
    nouJocTetris.baixaFigura();

    nouJocTetris.mostrarTualer();
    cout << endl;
    cout << endl;
    nouJocTetris.baixaFigura();

    nouJocTetris.mostrarTualer();
    cout << endl;
    cout << endl;
    nouJocTetris.baixaFigura();

    nouJocTetris.mostrarTualer();
    cout << endl;
}
/*
int main() 
{
    //mostrarCreacioFigures();
    //mostrarGirAntiHorari();
    //mostrarGirHorari();
    //escriuTaulerTest("testPosarFigura.txt", "archiuBuit.txt");
    //testEliminarFigura("testPosarFigura.txt");
    //testGirarFigura("testPosarFigura.txt");
    mouFigura("testPosarFigura.txt");
    return 0;
}
*/