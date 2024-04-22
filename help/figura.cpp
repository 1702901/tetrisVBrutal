#include "Figura.h"

#define TAMANY_ESTANDARD 9

Figuras::Figuras(int tipusFigura, int colorDesitjat)
{
    m_figura = tipusFigura;
    m_color = colorDesitjat;
    // borrar
    // inicializar array

    arrayToFigure(tipusFigura, m_arrayfiguras, m_tamany, m_color, m_lenghLine);
}
void Figuras::cambiaFigura(int tipusFigura)
{
    m_figura = tipusFigura;
    m_color = tipusFigura + 1 ;
    // borrar
    // inicializar array
    arrayToFigure(tipusFigura, m_arrayfiguras, m_tamany, m_color, m_lenghLine);
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
    int firstColumEndValue;
    switch (m_tamany)
    {
    case FIGURA_I_TAMANY:
        firstColumEndValue = 12;
        break;
    case FIGURA_O_TAMANY:
        firstColumEndValue = 2;
        break;
    case FIGURA_OTHERS_TAMANY:
        firstColumEndValue = 6;
        break;

    default:
        break;
    }
    int pos = 0;
    for (int colum = 0; colum < m_lenghLine; colum++)
    {
        // hem vist que podem descriure la trapostas a base d'aquesta  formula
        for (int element = 0; element <= firstColumEndValue; element += m_lenghLine)
        {
            copy[pos] = m_arrayfiguras[colum + element];
            pos++;
        }
    }
    for (int i = 0; i < pos; i++)
        m_arrayfiguras[i] = copy[i];
    delete copy;     
}


void Figuras::intercambiaFiles()
{
    int StartEndLine = 0;
    for (int i = 0; i < m_lenghLine - 1; i++)
        StartEndLine += m_lenghLine;
    int copy;
    for (int i = 0; i < m_lenghLine; i++)
    {
        copy = m_arrayfiguras[i];
        m_arrayfiguras[i] = m_arrayfiguras[i + StartEndLine];
        m_arrayfiguras[i + StartEndLine] = copy;
    }
    if (m_tamany == 16)
    {
        StartEndLine = m_lenghLine;
        for (int i = StartEndLine; i < StartEndLine + StartEndLine; i++)
        {
            copy = m_arrayfiguras[i];
            m_arrayfiguras[i] = m_arrayfiguras[i + m_lenghLine];
            m_arrayfiguras[i + m_lenghLine] = copy;
        }
    }
}

void Figuras::intercambiaColumnes()
{
    int FirstColum = 0;
    int EndColum = 0;
    for (int i = 0; i < m_lenghLine-1; i++)
        EndColum += m_lenghLine;
    int copy;
    int opositeColum;
    if (m_tamany == 16)
        opositeColum = 3;
    else
        opositeColum = 2;
    for (int i = FirstColum; i <= EndColum; i+=m_lenghLine)
    {
        copy = m_arrayfiguras[i];
        m_arrayfiguras[i] = m_arrayfiguras[i + opositeColum];
        m_arrayfiguras[i + opositeColum] = copy;
    }
    if(m_tamany == 16)
    {
        FirstColum = 1;
        EndColum++;
        for (int i = FirstColum; i <= EndColum; i += m_lenghLine)
        {
            copy = m_arrayfiguras[i];
            m_arrayfiguras[i] = m_arrayfiguras[i + 1];
            m_arrayfiguras[i + 1] = copy;
        }
    }
}
void Figuras::antiHorari()
{
    if (m_tamany != 4)
    {
        trasposarMatriu();
        intercambiaFiles();
    }
   
}

void Figuras::girHorari()
{

    if (m_tamany != 4)
    {
        trasposarMatriu();
        intercambiaColumnes();
    }    
}