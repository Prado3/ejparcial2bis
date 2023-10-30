#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

typedef struct {
    int idRegistro;
    int idPaciente;
    int idEspecialidad;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char especialidadMedica[30];
    char nombreDoctor[30];
}stRegistro;

#endif // REGISTRO_H_INCLUDED
