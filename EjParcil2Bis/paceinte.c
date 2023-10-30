#include "paciente.h"

void mostrarPaciente(stPaciente paciente){
    printf("\n idPaciente:..%d",paciente.idPaciente);
    printf("\n nombre:......%s",paciente.nombrePaciente);
    printf("\n apellido:....%s",paciente.apellidoPaciente);
    printf("\n diagnostico: %s",paciente.diagnostico);
    printf("\n Doctor:......%s",paciente.nombreDoctor);
    printf("\n fecha:.......%s",paciente.fechaAtencion);
}
