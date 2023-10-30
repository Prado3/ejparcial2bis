#include <stdio.h>
#include <stdlib.h>
#define ARCHI_REGIST "registroMedico.dat"
#define ARCHI_PAC "paciente.dat"
#include "celda.h"
#include "espeMedica.h"
#include "registro.h"
#define DIM 100

int agregarEspeCelda(celda adl[],int v);
int buscarEspe(celda adl[],int v,char espe[]);
int insertarEspe(celda adl[], char nombreArchi[],int v,int dim);
stPaciente registro2Paciente(stRegistro registro);
stEspeMedica registro2Espe(stRegistro registro);
int pasarArchi2Adl(char nombreArchi[],celda adl[],int v,int dim);
void mostrarEstructura(celda adl[],int v);
int buscarPacienteEnEspe(celda adl[],int v,char nombre[],char apellido[],char espe[]);
int buscarRecursivo(nodoPaciente* arbol,char nombre[],char apellido[], int flag);
void mostrarCantPacienteXEspe(celda adl[],int v);
int contarRecursivo(nodoPaciente* arbol,int cant);
void paciente2Archi(char nombreArchi[], celda adl[],int v,char espe[],int dim);
int pasarArbol2Arreglo(nodoPaciente* arbol, stPaciente pacientes[], int vP, int dim);
void mostrarArchi(char nomreArchi[]);

int main()
{
    int v = 0;
    int flag=0;
    char espe[30];
    char nombre[30];
    char apellido[30];
    celda adl[DIM];
    stPaciente pacientes[DIM];
    /// PUNTO 2
    v = agregarEspeCelda(adl,v);
    mostrarEstructura(adl,v);
    /// PUNTO 3
    //printf("\n Ingrese especialidad a buscar: ");
    //gets(espe);
    //flag = buscarEspe(adl,v,espe);
    //if(flag==0){
    //    printf("\n la especialidad no se encuentra..");
    //}else{
    //    printf("\n la especialidad %s se encuentra",espe);
    //}
    /// PUNTO 4
    //v = insertarEspe(adl,ARCHI_REGIST,v,DIM);
    //mostrarEstructura(adl,v);
    /// PUNTO 5
    //v = pasarArchi2Adl(ARCHI_REGIST,adl,v,DIM);
    /// PUNTO 6
    //mostrarEstructura(adl,v);
    /// PUNTO 7
    //printf("\n ingrese el nombre a buscar: ");
    //gets(nombre);
    //printf("\n ingrese el apellido a buscar: ");
    //gets(apellido);
    //flag = buscarPacienteEnEspe(adl,v,nombre,apellido,espe);
    //if(flag==0){
    //    printf("\n no se encontro el paciente..");
    //}else{
    //    printf("\n se encontro el paciente en la especialidad %s",espe);
    //}
    /// PUNTO 8
    //mostrarCantPacienteXEspe(adl,v);
    /// PUNTO 9
    //printf("\n ingrese especialidad a pasar al archivo: ");
    //gets(espe);
    //paciente2Archi(ARCHI_PAC,adl,v,espe,DIM);
    //mostrarArchi(ARCHI_PAC);



    return 0;
}

int agregarEspeCelda(celda adl[],int v){
    stEspeMedica espe;
    stPaciente paciente;
    if(v==0){
        espe = agregarEspe();
        v = alta(adl,v,paciente,espe);
    }else{
        for(int i=0;i<v;i++){
            if(i==v-1){
                espe = agregarEspe();
                v = alta(adl,v,paciente,espe);
            }
        }
    }
    return v;
}

int buscarEspe(celda adl[],int v,char espe[]){
    int flag=0;
    for(int i=0;i<v;i++){
        if(strcmp(adl[i].espe.especialidadMedica,espe)==0){
            flag=1;
        }
    }
    return flag;
}

int insertarEspe(celda adl[], char nombreArchi[],int v,int dim){
    stEspeMedica espe;
    stPaciente paciente;
    stRegistro registro;
    FILE* archi = fopen(nombreArchi,"a+b");
    if(archi){
        if(v<dim){
            fread(&registro,sizeof(stRegistro),1,archi);
            paciente = registro2Paciente(registro);
            espe = registro2Espe(registro);
            v = alta(adl,v,paciente,espe);
        }
    }
    return v;
}

stEspeMedica registro2Espe(stRegistro registro){
    stEspeMedica espe;
    strcpy(espe.especialidadMedica,registro.especialidadMedica);
    espe.idEspecialidad=registro.idEspecialidad;
    return espe;
}

stPaciente registro2Paciente(stRegistro registro){
    stPaciente paciente;
    strcpy(paciente.nombrePaciente,registro.nombrePaciente);
    strcpy(paciente.apellidoPaciente,registro.apellidoPaciente);
    strcpy(paciente.diagnostico,registro.diagnostico);
    strcpy(paciente.fechaAtencion,registro.fechaAtencion);
    strcpy(paciente.nombreDoctor,registro.nombreDoctor);
    paciente.idPaciente=registro.idPaciente;
    return paciente;
}

int pasarArchi2Adl(char nombreArchi[],celda adl[],int v,int dim){
    stEspeMedica espe;
    stPaciente paciente;
    stRegistro registro;
    FILE* archi = fopen(nombreArchi,"a+b");
    if(archi){
        while(v<dim && fread(&registro,sizeof(stRegistro),1,archi)>0){
            paciente = registro2Paciente(registro);
            espe = registro2Espe(registro);
            v = alta(adl,v,paciente,espe);
        }
        fclose(archi);
    }
    return v;
}

void mostrarEstructura(celda adl[],int v){
    for(int i=0;i<v;i++){
        mostrarEspecialidad(adl[i].espe);
        mostrarArbol(adl[i].nodoArbol);
    }
}

int buscarPacienteEnEspe(celda adl[],int v,char nombre[],char apellido[],char espe[]){
    int i=0;
    int flag=0;
    while(i<v && flag==0){
        flag = buscarRecursivo(adl[i].nodoArbol,nombre,apellido,flag);
        if(flag==1){
            strcpy(espe,adl[i].espe.especialidadMedica);
        }
        i++;
    }
    return flag;
}

int buscarRecursivo(nodoPaciente* arbol,char nombre[],char apellido[], int flag){
    if(arbol && flag==0){
        if(strcmp(arbol->paciente.nombrePaciente,nombre)==0 && strcmp(arbol->paciente.apellidoPaciente,apellido)==0){
            flag = 1;
        }
        flag = buscarRecursivo(arbol->izq,nombre,apellido,flag);
        flag = buscarRecursivo(arbol->der,nombre,apellido,flag);
    }
    return flag;
}

void mostrarCantPacienteXEspe(celda adl[],int v){
    for(int i=0;i<v;i++){
        int cant=0;
        cant = contarRecursivo(adl[i].nodoArbol,cant);
        printf("\n la cantidad de paciente en la especialidad %s es de %d",adl[i].espe.especialidadMedica,cant);
    }
}

int contarRecursivo(nodoPaciente* arbol,int cant){
    if(arbol){
        cant = contarRecursivo(arbol->izq,cant);
        cant = contarRecursivo(arbol->der,cant);
        cant++;
    }
    return cant;
}

void paciente2Archi(char nombreArchi[], celda adl[],int v,char espe[],int dim){
    FILE* archi = fopen(nombreArchi,"a+b");
    stPaciente pacientes[dim];
    stPaciente paciente;
    int vP=0;
    for(int i=0;i<v;i++){
        if(strcmp(adl[i].espe.especialidadMedica,espe)==0){
            vP = pasarArbol2Arreglo(adl[i].nodoArbol,pacientes,vP,dim);
        }
    }
    if(archi){
        for(int j=0;j<vP;j++){
            paciente=pacientes[j];
            fwrite(&paciente,sizeof(stPaciente),1,archi);
        }
        fclose(archi);
    }
}

int pasarArbol2Arreglo(nodoPaciente* arbol, stPaciente pacientes[], int vP, int dim){
    if(arbol){
        vP = pasarArbol2Arreglo(arbol->izq,pacientes,vP,dim);
        vP = pasarArbol2Arreglo(arbol->der,pacientes,vP,dim);
        if(vP<dim){
            pacientes[vP] = arbol->paciente;
            vP++;
        }
    }
    return vP;
}

void mostrarArchi(char nomreArchi[]){
    FILE* archi = fopen(nomreArchi,"rb");
    stPaciente paciente;
    if(archi){
        while(fread(&paciente,sizeof(stPaciente),1,archi)>0){
            mostrarPaciente(paciente);
        }
    }
}
