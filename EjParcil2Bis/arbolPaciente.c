#include "arbolPaciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

nodoPaciente* inicArbol(){
    return NULL;
}

nodoPaciente* crearNodo(stPaciente paciente){
    nodoPaciente* nuevo = (nodoPaciente*) malloc(sizeof(nodoPaciente));
    nuevo->paciente = paciente;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoPaciente* agregarArbol(nodoPaciente* arbol, stPaciente paciente){
    if(!arbol){
        arbol = crearNodo(paciente);
    }else{
        if(arbol->paciente.idPaciente<paciente.idPaciente){
            arbol->der = agregarArbol(arbol->der,paciente);
        }else{
            if(arbol->paciente.idPaciente!=paciente.idPaciente){
                arbol->izq = agregarArbol(arbol->izq,paciente);
            }
        }
    }
    return arbol;
}

void mostrarArbol(nodoPaciente* arbol){
    if(arbol){
        mostrarArbol(arbol->izq);
        mostrarPaciente(arbol->paciente);
        mostrarArbol(arbol->der);
    }
}
