#include "header.h"
using namespace std;


//TODO : Interface
        /*
        1. Uso das fun��es desenvolvidas para �rvore
        */
//TODO : Implementa��o
        /*
        1.Opera��es da �rvore
            - CORRIGIR contadores.
            - APLICAR fun��es de remo��o e destrui��o
        2. Gerenciar Opera��es
            - Checagens de par�metros
            - Debug
        */

int main(){

    setlocale(LC_ALL,"Portuguese");

    cout<< "\nWELCOME TO YGGDRASIL HANDLER\t\
    \tBST Designed by Jonas Jakiminski Silva.\n\
    Your number 1 BinarySearchTree Management App.\n";
    continue_button();

    //DECLARA��ES
    ////////////////////////

        // STATUS de opera��es
    int exitStatus = FALSE; // atribuir TRUE: close window
    void* dado = 0; // recebe Query
        // ENTRADA DO USU�RIO
    int* input = new int;  // input principal
    int key = 0;    // input key
    int options = 0; // Define a opera��o do usu�rio
    int consulta = 0;  // Define m�todo de consulta

    //MENU
    ////////////////////////

    BSTree* tree = bstCreate();
    if (tree==NULL) cout<< "NAO EXISTE ARVORE\n";

    do{
        // TREE PROFILE
        /*
        cout<< "\nN�mero de n�s:\t"<<bstCountNode(tree->root)<<endl;
        cout<< "Folhas: "<<bstCountLeaf(tree->root)<<"\t";
        cout<< "Grau 1: "<<bstCountNode1(tree->root)<<"\t";
        cout<< "Grau 2: "<<bstCountNode2(tree->root)<<"\t";
        //TODO: ALTURA e MENOR/MAIOR ELEMENTO
        cout<<endl;
        */

        //MENU DE OPERA��ES NA �RVORE
        menu(&options);

        switch(options){
        case INSERT:
        // Inser��o de dado em um novo n�
            cout<< "\nForne�a um dado para inser��o.\n";
            input = new int;
            scanf("%d",input);
            system("cls");
            tree->root = bstTreeInsert(tree->root,(void*)input,cmp);

            if (tree->root!=NULL){
                cout<< "\n"<<*input<<" inserido na �rvore bin�ria com sucesso.\n";
            }else{
                cerr<< "\nERRO:\t"<<*input<<" n�o foi inserido na �rvore.\n";
            }
            continue_button();
            break;

        case QUERY:
        // Consulta dado(s) em �rvore
            cout<< "\nDefina uma op��o:\n";
            cout<< "\n[1]Imprimir �rvore Pr�-Ordem\n[2]Imprimir �rvore Em-Ordem";
            cout<< "\n[3]Imprimir �rvore P�s-Ordem\n[4]Consultar elemento na �rvore";
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
                cout<< "\nForne�a um dado para consulta.\n";
                scanf("%d",&key);
                dado = bstTreeQuery(tree->root,(void*)&key,cmp);
                if (dado!=NULL){
                cout<< "\n"<<(int)dado <<" est� na �rvore.\n";
                }else{
                    cout<< "\n"<<key<<" n�o foi encontrado.\n";
                }
            }else if (consulta==0){
                continue_button();
                continue;// Volta pro LOOP do menu
            }
            cout<<endl;

            break;

        case REMOVE:
        // Remove n� da �rvore
            //int bstTreeRemove(BSTree*,void*,void*,int(*cmp)(void*,void*));
            cout<< "\nForne�a um dado para remo��o.\n";
            scanf("%d",&key);
            system("cls");
            tree->root = bstTreeRemove(tree->root,(void*)&key,(void**)&input,cmp);

            if (bstTreeQuery(tree->root,(void*)&key,cmp)!=NULL){
                cout<< "\n"<<input<<" removido da �rvore bin�ria com sucesso.\n";
            }else{
                cerr<< "\nWARNING:\t"<<key<<" n�o foi removido ou n�o est� na �rvore.\n";
            }
            continue_button();
            break;

        case DESTROY:
        // Destr�i �rvore sem elementos
            exitStatus = bstDestroy(tree);
            cout<< "EXIT STATUS = "<<exitStatus<<endl;
            continue_button();
            //SAIR DA APLICA��O IDEALMENTE
            if (exitStatus){
                cout<< "\n\tCIAO!\n";
                return EXIT_SUCCESS;
            }
            break;
        /*
        case EXIT:
        // For�a destrui��o da �rvore e sai do programa
            cout<< "EXIT STATUS = "<<exitStatus<<endl;
            continue_button();
            //SAIR DA APLICA��O IDEALMENTE
            if (exitStatus){
                cout<< "\n\tCIAO!\n";
                return EXIT_SUCCESS;
            }
            break;
        */
        }

    }while(!exitStatus);

    //SAIR DA APLICA��O INESPERADAMENTE
    cerr<< "\nFinalizando programa inesperadamente :(\n";
    return EXIT_FAILURE;

}
