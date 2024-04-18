#ifndef STRUCT_H
#define STRUCT_H

#include "math.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int COLUMNESATAULER = 8;
const int FILESTAULER = 8;
const int DIMENSIONS = 2;

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
    NO_COLOR
} ColorFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

#endif
