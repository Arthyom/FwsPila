#ifndef FWSPILA_H
#define FWSPILA_H
/*******************************************************************************************************
 ***************************************** Libreria para Pilas *****************************************
 *******************************************************************************************************/


#include "C:/Users/frodo/Documents/GitHub/FwsNode/FwsNode.h"

/******************************************************************************************
 ******************************** Declarar el tipo FwsPila ********************************
 ******************************************************************************************/
typedef struct {
    FwsNode * PilaCima;
    FwsNode * PilaFondo;
    int       PilaDims;
}FwsPila;

/******************************************************************************************
 ******************************* funciones del tipo FwsPila *******************************
 ******************************************************************************************/

FwsPila *   FwsPilaCrear        (){

    FwsPila * nuevaPila =(FwsPila*)malloc(sizeof(FwsPila));
    nuevaPila->PilaDims = 0;
    nuevaPila->PilaFondo = NULL;
    nuevaPila->PilaCima  = NULL;

    return nuevaPila;
}

void        FwsPilaPop          ( FwsPila * pilaEntrada ){

    FwsNode * nodoCimaAux = pilaEntrada->PilaCima->nodeSiguiente;
    pilaEntrada->PilaCima = nodoCimaAux;
    pilaEntrada->PilaDims --;

}

void        FwsPilaPush         ( FwsPila * pilaEntrada, FwsNode * nodoEntrada ){

    nodoEntrada->nodeSiguiente = pilaEntrada->PilaCima;
    pilaEntrada->PilaCima = nodoEntrada;
    pilaEntrada->PilaDims++;

}

void        FwsPilaPrint        ( FwsPila * pilaEntrada, int modo  ){

    FwsNode * nodoAuxPila = pilaEntrada->PilaCima;
    while( nodoAuxPila ){
        switch (modo){
            case 1: printf("% d \n | \n V \n \n", *((int*)nodoAuxPila->nodeValue)); break;

            case 2: printf("% f \n 1 \n V \n \n", *((float*)nodoAuxPila->nodeValue)); break;

            case 3: printf("% c \n 1 \n V \n \n", *((char*)nodoAuxPila->nodeValue)); break;

        }
        nodoAuxPila = nodoAuxPila->nodeSiguiente;
    }

}

int         FwsPilaPopAt        ( FwsPila * pilaEntrada, int pos){

    int posRecorrida = 0 ;
    FwsNode * nodoAuxPila = pilaEntrada->PilaCima;

    // recorrer la pila hasta encontar el elemento especificado (solo para pos > pila-> dis && numeros positivos
    if (  (pos  <= pilaEntrada->PilaDims ) && pos > 0){
        while( posRecorrida < pos  ){
            FwsPilaPop(pilaEntrada);
            posRecorrida++;
        }
    }

    return 0;
}


#endif // FWSPILA_H
