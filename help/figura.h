#ifndef FIGURA_H
#define FIGURA_H

#include "struct.h"
#include "D:\Uni\Metdologia de la programacion\tetris\funcionAuxiliar.h"
#define TAMANY_ESTANDARD 9
#define TAMANY_MES_GRAN 16

class Figuras
{
private:
    int arrayfiguras[TAMANY_MES_GRAN];
    int lenghLine;
    int color;
    int figura;
    int tamany;
public:
    Figuras(int tipusFigura, int colorDesitjat);
    ~Figuras();
    void trasposarMatriu();
    void girHorari();
    void antiHorari();
    void trasposarFiguraLinea();
    void intercambiaFiles();
    void intercambiaColumnes();
    void inicialitzaArray() { for (int i = 0; i < TAMANY_MES_GRAN; i++) { arrayfiguras[i] = 0; } };
    int getTamany() const { return tamany; }
    void getArray(int* array) { for (int i = 0; i < tamany; i++) { array[i] = arrayfiguras[i]; } };
};

ostream& operator<<(ostream &out, Figuras figuraAmostra);




#endif
