#include "celda.h"
#include "arbolPaciente.h"

int alta(celda adl[],int v,stPaciente paciente,stEspeMedica espe){
    int pos = buscarPos(adl,v,espe);
    if(pos==-1){
        v = agregarCelda(adl,v,espe);
        pos = v-1;
    }
    adl[pos].nodoArbol = agregarArbol(adl[pos].nodoArbol,paciente);
    return v;
}

int buscarPos(celda adl[],int v,stEspeMedica espe){
    int pos=-1;
    int i=0;

    while(i<v && pos==-1){
        if(adl[i].espe.idEspecialidad==espe.idEspecialidad){
            pos=i;
        }
        i++;
    }
    return pos;
}

int agregarCelda(celda adl[],int v,stEspeMedica espe){
    adl[v].espe = espe;
    adl[v].nodoArbol = inicArbol();
    return v+1;
}
