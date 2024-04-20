#include "funcionAuxiliar.h"


// Anexo 1
void numToBinary(int num, bool array[])
{
    array[2] = (num >> 0) & 1;
    array[1] = (num >> 1) & 1;
    array[0] = (num >> 2) & 1;   
} 

void bynaryToFigure(bool* num, int* array, const int color)
{
    array[4] = color;
    if (num[2])
    {
        if (num[1])
        {
            array[2] = color;
            array[3] = color;
            array[0] = 0;
            array[1] = 0;
            array[5] = color;
        }
        else
        {
            array[5] = color;
            array[0] = color;
            array[3] = 0;
            if (num[0])
            {
                array[1] = color;
                array[2] = 0; 
            }
            else
            {
                array[1] = 0;
                array[2] = color;
            }
        }
    }
    else
    {
        array[3] = color;
        if (num[1])
        {
            array[0] = 0;
            array[1] = color;
            if (num[0])
            {
                array[5] = 0;
                array[2] = color;
            }
            else
            {
                array[2] = 0;
                array[5] = color;
            }
        }
        else
        {
            array[1] = 0;
            array[2] = 0;
            array[0] = color;
            array[5] = color;
        }
    }
    /*
    bool saveRepetedValue = num[0] && num[2];
    array[0] = (!num[1] || saveRepetedValue) * color;
    array[1] = ((!num[2] && num[1])||saveRepetedValue)*color;
    array[2] = ((!num[0] && num[2]) || (num[0] && num[1])) * color;
    array[3] = (!num[2]|| num[1]) * color;
    array[4] = color;
    array[5] = (!num[0]|| !num[1])*color;
    */
}

// Anexo 2
void arrayToFigure(int tipusFigura, int array[],int& tamany, const int color, int& lenghLine)
{ 
    switch (tipusFigura)
    {
    case FIGURA_O:
        for (int i = 0; i < FIGURA_O_TAMANY; i++)
            array[i] = color;
        tamany=4;
        lenghLine = 2;
        break;
    case FIGURA_I:
        tamany = 16;
        for (int i = 0; i < tamany; i++)
            array[i] = 0;
        array[4] = color; 
        array[5] = color; 
        array[6] = color; 
        array[7] = color; 
        lenghLine = 4;
        break;
    default:
        // Quitar if else cuando se este en una etapa mas avanzada y solo dejar
        // lo que esta dentro del if ya que solo habra ese tipo de figura y no se pasaran figuras erronea
        if (tipusFigura > FIGURA_I && tipusFigura < NO_FIGURA)
        {
            lenghLine = 3;
            tamany = 9;
            const int todo0Inicio = 6;
            // La ultima fila siempre termina en 0
            for (int i = todo0Inicio; i < tamany; i++)
                array[i] = 0;
            bool num[3];
            numToBinary(tipusFigura, num);
            bynaryToFigure(num, array, color);
        }
        else
            cout << "error no se encontro la figura" << endl;
        break;
    }
}


// explicacion en 

void intercambia(int& num1,int& num2)
{
    int copy = num1;
    num1 = num2;
    num2 = copy;
}