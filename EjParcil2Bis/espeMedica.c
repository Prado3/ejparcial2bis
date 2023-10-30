#include "espeMedica.h"

void mostrarEspecialidad(stEspeMedica especialidad){
    printf("\n ===============================================");
    printf("\n idEspecialidad:....%d",especialidad.idEspecialidad);
    printf("\n Especialidad:......%s",especialidad.especialidadMedica);
    printf("\n ===============================================");
}

stEspeMedica agregarEspe(){
    stEspeMedica espe;
    printf("\n Ingrese la especialidad a agregar: ");
    gets(espe.especialidadMedica);

    espe.idEspecialidad=rand()%300000;

    return espe;
}
