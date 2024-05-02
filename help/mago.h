#ifndef MAGO_H
#define MAGO_H
#include "struct.h"
class mago
{
private:
	int vida;
public:
	mago(): vida(MAX_VIDA_MAGO) { };
	int getVida() const { return vida; };
	void baixaVida() { vida--; };
	void pujaVida() { vida++; }
};

#endif