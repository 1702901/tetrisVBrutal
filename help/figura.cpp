#include "figura.h"

#define TAMANY_ESTANDARD 9

Figuras::Figuras(int tipusFigura, int colorDesitjat)
{
    figura = tipusFigura;
    color = colorDesitjat;
    // borrar
    // inicializar array

    arrayToFiguire(tipusFigura, arrayfiguras, tamany, color);
}

Figuras::~Figuras()
{
}

ostream& operator<<(ostream &out, Figuras figuraAmostra)
{
    int tamanyFigura = figuraAmostra.getTamany();
    int arrayMostar[TAMANY_MES_GRAN];
    figuraAmostra.getArray(arrayMostar);
    int lenghLine = int(sqrt(tamanyFigura));
    string lineaMostrar;
    int colum = 0;
    for (int linea = 0; linea < lenghLine; linea++)
    {
        lineaMostrar = "[";

        for (int i = 0; i < lenghLine-1; i++)
        {
            lineaMostrar = lineaMostrar + to_string(arrayMostar[colum]) + ",";
            colum++;
        }
        lineaMostrar = lineaMostrar + to_string(arrayMostar[colum]) + "]";
        colum++;
        out << lineaMostrar << endl;
    }
    return out;
}

void Figuras::trasposarMatriu()
{
    if (tamany!=4)
    {
        int *copy = new int[tamany];
        int ELEMENTS_LINEARS;
        switch (tamany)
        {
        case FIGURA_I_TAMANY:
            ELEMENTS_LINEARS = 4;
            break;
        case FIGURA_O_TAMANY:
            ELEMENTS_LINEARS = 2;
            break;
        case FIGURA_OTHERS_TAMANY:
            ELEMENTS_LINEARS = 3;
            break;

        default:
            break;
        }
        int pos = 0;
        for (int colum = 0; colum < ELEMENTS_LINEARS; colum++)
        {
            // hem vist que podem descriure la trapostas a base d'aquesta  formula
            for (int element = 0; element <= colum + ELEMENTS_LINEARS * 2; element += 3)
            {
                copy[pos] = arrayfiguras[colum + element];
                pos++;
            }
        }
        for (int i = 0; i < pos; i++)
            arrayfiguras[i] = copy[i];
        delete copy;
    }     
}

void Figuras::girHorari()
{
    trasposarMatriu();


}
void Figuras::antiHorari()
{
    if (tamany == 16)
    {
        if (arrayfiguras[2] == color)
        {
            arrayfiguras[2]=0;
            arrayfiguras[10]=0;
            arrayfiguras[14]=0;
            arrayfiguras[4]=color;
            arrayfiguras[5]=color;
            arrayfiguras[7]=color;
        }
        else
        {
            arrayfiguras[2]=color;
            arrayfiguras[10]=color;
            arrayfiguras[14]=color;
            arrayfiguras[4]=0;
            arrayfiguras[5]=0;
            arrayfiguras[7]=0;
        }
    }
    else
    {
        trasposarMatriu();
        // faltan cosas
    }
    
}