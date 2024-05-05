#ifndef STRUCT_H
#define STRUCT_H

#include "math.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <conio.h>
#include <chrono>
#include <ctime>

using namespace std;

const int COLUMNESATAULER = 8;
const int FILESTAULER = 16;
const int DIMENSIONS = 2;
const int MAX_FILA = FILESTAULER ;
const int MAX_COL = COLUMNESATAULER;
const int MAX_GIRS = 3;
const int MAX_VIDA_MAGO = 3;

typedef enum
{
    FIGURA_O_TAMANY = 4,
    FIGURA_I_TAMANY = 16,
    FIGURA_OTHERS_TAMANY=9,
    NO_FIGURA_TAMANY = 0
} TamanyFigura;

typedef enum
{
    FIGURA_O = 0,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
    NO_FIGURA
} TipusFigura;

// Color negre = posicio vuida
typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_BLAUCEL,
    COLOR_GROC,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERD,
    COLOR_VERMELL,
    NO_COLOR,
    SLIME
} ColorFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

#endif