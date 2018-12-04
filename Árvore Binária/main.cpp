#include "header.h"
using namespace std;


//TODO : Interface
        /*
        1. Uso das funções desenvolvidas para árvore
        */
//TODO : Implementação
        /*
        1.Operações da Árvore
            - CORRIGIR contadores.
            - APLICAR funções de remoção e destruição
        2. Gerenciar Operações
            - Checagens de parâmetros
            - Debug
        */

int main(){

    setlocale(LC_ALL,"Portuguese");

    cout<< "\nWELCOME TO YGGDRASIL HANDLER\t\
    \tBST Designed by Jonas Jakiminski Silva.\n\
    Your number 1 BinarySearchTree Management App.\n";
    continue_button();

    //DECLARAÇÕES
    ////////////////////////

        // STATUS de operações
    int exitStatus = FALSE; // atribuir TRUE: close window
    void* dado = 0; // recebe Query
        // ENTRADA DO USUÁRIO
    int* input = new int;  // input principal
    int key = 0;    // input key
    int options = 0; // Define a operação do usuário
    int consulta = 0;  // Define método de consulta

    //MENU
    ////////////////////////

    BSTree* tree = bstCreate();
    if (tree==NULL) cout<< "NAO EXISTE ARVORE\n";

    do{
        // TREE PROFILE
        /*
        cout<< "\nNúmero de nós:\t"<<bstCountNode(tree->root)<<endl;
        cout<< "Folhas: "<<bstCountLeaf(tree->root)<<"\t";
        cout<< "Grau 1: "<<bstCountNode1(tree->root)<<"\t";
        cout<< "Grau 2: "<<bstCountNode2(tree->root)<<"\t";
        //TODO: ALTURA e MENOR/MAIOR ELEMENTO
        cout<<endl;
        */

        //MENU DE OPERAÇÕES NA ÁRVORE
        menu(&options);

        switch(options){
        case INSERT:
        // Inserção de dado em um novo nó
            cout<< "\nForneça um dado para inserção.\n";
            input = new int;
            scanf("%d",input);
            system("cls");
            tree->root = bstTreeInsert(tree->root,(void*)input,cmp);

            if (tree->root!=NULL){
                cout<< "\n"<<*input<<" inserido na árvore binária com sucesso.\n";
            }else{
                cerr<< "\nERRO:\t"<<*input<<" não foi inserido na árvore.\n";
            }
            continue_button();
            break;

        case QUERY:
        // Consulta dado(s) em árvore
            cout<< "\nDefina uma opção:\n";
            cout<< "\n[1]Imprimir Árvore Pré-Ordem\n[2]Imprimir Árvore Em-Ordem";
            cout<< "\n[3]Imprimir Árvore Pós-Ordem\n[4]Consultar elemento na Árvore";
            cout<< "\nPressione [0] ZERO para voltar ao menu.\n";
            cout<< endl;

            scanf("%d",&consulta);

            if(consulta==1){
                cout<< "PRE ORDER:\t";
                bstTreePreOrder(tree->root,visit);
            }else if (consulta==2){
                cout<< "IN ORDER:\t";
                bstTreeInOrder(tree->root,visit);
            }else if (consulta==3){
                cout<< "POST ORDER:\t";
                bstTreePostOrder(tree->root,visit);
            }else if (consulta==4){
                cout<< "\nForneça um dado para consulta.\n";
                scanf("%d",&key);
                dado = bstTreeQuery(tree->root,(void*)&key,cmp);
                if (dado!=NULL){
                cout<< "\n"<<(int)dado <<" está na árvore.\n";
                }else{
                    cout<< "\n"<<key<<" não foi encontrado.\n";
                }
            }else if (consulta==0){
                continue_button();
                continue;// Volta pro LOOP do menu
            }
            cout<<endl;

            break;

        case REMOVE:
        // Remove nó da árvore
            //int bstTreeRemove(BSTree*,void*,void*,int(*cmp)(void*,void*));
            cout<< "\nForneça um dado para remoção.\n";
            scanf("%d",&key);
            system("cls");
            tree->root = bstTreeRemove(tree->root,(void*)&key,(void**)&input,cmp);

            if (bstTreeQuery(tree->root,(void*)&key,cmp)!=NULL){
                cout<< "\n"<<input<<" removido da árvore binária com sucesso.\n";
            }else{
                cerr<< "\nWARNING:\t"<<key<<" não foi removido ou não está na árvore.\n";
            }
            continue_button();
            break;

        case DESTROY:
        // Destrói Árvore sem elementos
            exitStatus = bstDestroy(tree);
            cout<< "EXIT STATUS = "<<exitStatus<<endl;
            continue_button();
            //SAIR DA APLICAÇÃO IDEALMENTE
            if (exitStatus){
                cout<< "\n\tCIAO!\n";
                return EXIT_SUCCESS;
            }
            break;
        /*
        case EXIT:
        // Força destruição da árvore e sai do programa
            cout<< "EXIT STATUS = "<<exitStatus<<endl;
            continue_button();
            //SAIR DA APLICAÇÃO IDEALMENTE
            if (exitStatus){
                cout<< "\n\tCIAO!\n";
                return EXIT_SUCCESS;
            }
            break;
        */
        }

    }while(!exitStatus);

    //SAIR DA APLICAÇÃO INESPERADAMENTE
    cerr<< "\nFinalizando programa inesperadamente :(\n";
    return EXIT_FAILURE;

}
