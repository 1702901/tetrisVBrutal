#include "figura.h"

#define TAMANY_ESTANDARD 9

Figuras::Figuras(int tipusFigura, int colorDesitjat)
{
    m_figura = tipusFigura;
    m_color = colorDesitjat;
    // borrar
    // inicializar array

    arrayToFiguire(tipusFigura, m_arrayfiguras, m_tamany, m_color, m_lenghLine);
}
void Figuras::cambiaFigura(int tipusFigura)
{
    m_figura = tipusFigura;
    m_color = tipusFigura + 1 ;
    // borrar
    // inicializar array

    arrayToFiguire(tipusFigura, m_arrayfiguras, m_tamany, m_color, m_lenghLine);
}

Figuras::~Figuras()
{
}

ostream& operator<<(ostream &out,const Figuras& figuraAmostra)
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
    // Anexo 3
    int *copy = new int[m_tamany];
    int ELEMENTS_LINEARS;
    switch (m_tamany)
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
            copy[pos] = m_arrayfiguras[colum + element];
            pos++;
        }
    }
    for (int i = 0; i < pos; i++)
        m_arrayfiguras[i] = copy[i];
    delete copy;     
}



void Figuras::trasposarFiguraLinea()
{
    if (m_arrayfiguras[2] == m_color)
    {
        m_arrayfiguras[2] = 0;
        m_arrayfiguras[10] = 0;
        m_arrayfiguras[14] = 0;
        m_arrayfiguras[4] = m_color;
        m_arrayfiguras[5] = m_color;
        m_arrayfiguras[7] = m_color;
    }
    else
    {
        m_arrayfiguras[2] = m_color;
        m_arrayfiguras[10] = m_color;
        m_arrayfiguras[14] = m_color;
        m_arrayfiguras[4] = 0;
        m_arrayfiguras[5] = 0;
        m_arrayfiguras[7] = 0;
    }
}

void Figuras::intercambiaFiles()
{
    int posFigureArray;
    const int EndFirstLine = 3;
    const int StartEndLine = 6;
    int copy;
    for (int i = 0; i < EndFirstLine; i++)
    {
        copy = m_arrayfiguras[i];
        m_arrayfiguras[i] = m_arrayfiguras[i + StartEndLine];
        m_arrayfiguras[i + StartEndLine] = copy;
    }
}

void Figuras::intercambiaColumnes()
{
    int posFigureArray;
    const int FirstColum = 0;
    const int EndColum = 2;
    const int EndFirstColum = 6;
    int copy;
    for (int i = FirstColum; i <= EndFirstColum; i+=3)
    {
        copy = m_arrayfiguras[i];
        m_arrayfiguras[i] = m_arrayfiguras[i + EndColum];
        m_arrayfiguras[i + EndColum] = copy;
    }
}
void Figuras::antiHorari()
{
    if (m_tamany == 16)
        trasposarFiguraLinea();
    else
    {
        if (m_tamany != 4)
        {
            trasposarMatriu();
            intercambiaFiles();
            // faltan cosas
        }
    }
   
}

void Figuras::girHorari()
{

    if (m_tamany == 16)
        trasposarFiguraLinea();
    else
    {
        if (m_tamany != 4)
        {
            trasposarMatriu();
            intercambiaColumnes();
            // faltan cosas
        }
    }
}