#ifndef ARBOLPACIENTE_H_INCLUDED
#define ARBOLPACIENTE_H_INCLUDED

#include "paciente.h"

typedef struct _nodoPaciente{
    stPaciente paciente;
    struct _nodoPaciente* izq;
    struct _nodoPaciente* der;
}nodoPaciente;

nodoPaciente* inicArbol();
nodoPaciente* crearNodo(stPaciente paciente);
nodoPaciente* agregarArbol(nodoPaciente* arbol, stPaciente paciente);

#endif // ARBOLPACIENTE_H_INCLUDED
