#include "header.h"
using namespace std;

void menu(int *opcao){

    do{
        // Exibição da Lista de Operações
        cout<< "\n["<<INSERT<<"]:\t Insert data";
        cout<< "\n["<<QUERY<<"]:\t Query data";
        cout<< "\n["<<REMOVE<<"]:\t Remove data";
        cout<< "\n["<<DESTROY<<"]:\t Destroy an empty tree";
        cout<< "\n["<<EXIT<<"]:\t Force EXIT\n";
        // Entrada a partir do int opcao
        cin>> (*opcao);
        if ((*opcao)<0 || (*opcao)>4){
            cerr<< "\nNão há operação "<<*opcao<<" sobre a árvore.\n";
            continue_button();
        }
    }while((*opcao)<0 || (*opcao)>4);
    continue_button();

}
void continue_button(){

    cout<< "\nPress any key to continue.\n";
    cin.ignore();

}
