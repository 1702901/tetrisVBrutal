#include "figura.h"
#include "test.h"


void mostrarCreacioFigures()
{
    //mostra com es generen correctement totes les figures 
    
    for (int figura = 0; figura < 7; figura++)
    {
        Figuras novaFigura(figura , 4);
        cout << novaFigura << endl;
    }
    
}


int main() 
{
    // mostra com es generen correctement totes les figures 
    /*
    for (int figura = 0; figura < 7; figura++)
    {
        Figuras novaFigura(figura , 4);
        cout << novaFigura << endl;
    }
    */

    mostrarCreacioFigures();

    Figuras novaFigura(1, 4);
    //cout << novaFigura << endl;
    //novaFigura.antiHorari();
    //cout << novaFigura << endl;

    return 0;
}