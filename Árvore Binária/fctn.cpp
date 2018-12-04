#include "header.h"
using namespace std;

// Comparação chave&dado

int cmp(void*key,void* elem){

    int* ptrKey = (int*) key;
    int* ptrElem = (int*) elem;

    if (ptrKey<ptrElem)
        return -1; //Key é MENOR
    else if (ptrKey<ptrElem)
        return  1; //Key é MAIOR
    else
        return 0; // Elem==Key

}

// Visitação

void visit(void* data){

    if (data!=NULL){
        int* dado = (int*)data;
        cout<<*dado<<"\t";
    }

}
