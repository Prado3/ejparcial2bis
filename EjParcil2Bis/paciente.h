#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct {
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[30];
    char fechaAtencion[30];
    char nombreDoctor[30];
}stPaciente;

void mostrarPaciente(stPaciente apciente);

#endif // PACIENTE_H_INCLUDED
