#ifndef CELDA_H_INCLUDED
#define CELDA_H_INCLUDED

#include "arbolPaciente.h"
#include "espeMedica.h"

typedef struct {
    stEspeMedica espe;
    nodoPaciente* nodoArbol;
}celda;

int alta(celda adl[],int v,stPaciente paciente,stEspeMedica espe);
int buscarPos(celda adl[],int v,stEspeMedica espe);
int agregarCelda(celda adl[],int v,stEspeMedica espe);

#endif // CELDA_H_INCLUDED
