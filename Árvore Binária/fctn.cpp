#include "header.h"
using namespace std;

// Compara��o chave&dado

int cmp(void*key,void* elem){

    int* ptrKey = (int*) key;
    int* ptrElem = (int*) elem;

    if (ptrKey<ptrElem)
        return -1; //Key � MENOR
    else if (ptrKey<ptrElem)
        return  1; //Key � MAIOR
    else
        return 0; // Elem==Key

}

// Visita��o

void visit(void* data){

    if (data!=NULL){
        int* dado = (int*)data;
        cout<<*dado<<"\t";
    }

}
