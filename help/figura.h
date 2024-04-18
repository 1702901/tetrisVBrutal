#ifndef FIGURA_H
#define FIGURA_H

#include "struct.h"
#include "D:\Uni\Metdologia de la programacion\tetris\funcionAuxiliar.h"
#define TAMANY_ESTANDARD 9
#define TAMANY_MES_GRAN 16

class Figuras
{
private:
    int m_arrayfiguras[TAMANY_MES_GRAN];
    int m_lenghLine;
    int m_color;
    int m_figura;
    int m_tamany;
    int punt[DIMENSIONS];
public:
    Figuras(int tipusFigura, int colorDesitjat);
    Figuras() {};
    ~Figuras();
    void cambiaFigura(int tipusFigura);
    void trasposarMatriu();
    void girHorari();
    void antiHorari();
    void trasposarFiguraLinea();
    void intercambiaFiles();
    void intercambiaColumnes();
    void inicialitzaArray() { for (int i = 0; i < TAMANY_MES_GRAN; i++) { m_arrayfiguras[i] = 0; } };
    int getTamany() const { return m_tamany; }
    void getArray(int* array) const { for (int i = 0; i < m_tamany; i++) { array[i] = m_arrayfiguras[i]; } };
    void setX(const int coordenaX) { punt[0] = coordenaX; }
    void setY(const int coordenaY) { punt[1] = coordenaY; }
    int getX() const { return punt[0]; }
    int getY() const{ return punt[1]; }



};

ostream& operator<<(ostream &out,const Figuras& figuraAmostra);




#endif
