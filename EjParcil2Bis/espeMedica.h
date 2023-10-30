#ifndef ESPEMEDICA_H_INCLUDED
#define ESPEMEDICA_H_INCLUDED

#include "espeMedica.h"

typedef struct {
    int idEspecialidad;
    char especialidadMedica[30];
}stEspeMedica;

void mostrarEspecialidad(stEspeMedica especialidad);
stEspeMedica agregarEspe();

#endif // ESPEMEDICA_H_INCLUDED
