#include "header.h"
using namespace std;

BSTree* bstCreate(void){

    BSTree* tree = new BSTree;
    if (tree!=NULL){
        tree->root=NULL;
        return tree;
    }
    cerr<< "\nERRO:\t Árvore não foi inicializada.\n";
    return NULL;

}

int bstDestroy(BSTree* tree){

    int flag = FALSE;
    if (tree!=NULL){
        if (tree->root==NULL){
            delete tree;
            flag = TRUE;
        }
        if (!flag) cerr<< "\nERRO:\tÁrvore não está vazia\n";
        else cout<< "\nÁrvore destruída com sucesso\n";

        return flag;
    }
    cerr<< "\nERRO:\tÁrvore não existente ou não foi alocada\n";
    return FALSE;

}

int bstTreeIsEmpty(BSTree* tree){

    if (tree!=NULL){
        int boo = (tree->root==NULL)? TRUE:FALSE;
        return boo;
    }
    cerr<< "\nERROR:\tThere's no valid tree found.";
    return FALSE;

}
int bstNodeLeftSon(TNode* node){

    if (node!=NULL){
        int boo = (node->left!=NULL)? TRUE:FALSE;
        return boo;
    }
    cerr<< "\nERROR:\tInvalid node.\n";
    return FALSE;

}
int bstNodeRightSon(TNode* node){

    if (node!=NULL){
        int boo = (node->right!=NULL)? TRUE:FALSE;
        return boo;
    }
    cerr<< "\nERROR:\tInvalid node.\n";
    return FALSE;

}
int bstNodeIsLeaf(TNode* node){

    if (node!=NULL){
        int L = bstNodeLeftSon(node);
        int R = bstNodeRightSon(node);

        return L&&R;
    }
    cerr<< "\nERROR:\tInvalid node.\n";
    return FALSE;

}

int bstNodeBranch(TNode* node){

    if (node!=NULL){
        // "Teste de gravidez"
        int branch = 0; //Deu Negativo
        // Pode ser positivo :v
        branch += bstNodeLeftSon(node);//Add 1 if TRUE, 0 if FALSE
        branch += bstNodeRightSon(node);// O grau incrementa pra cada filho

        return branch;
    }
    cerr<< "\nERROR:\tInvalid node.\n";
    return -1;
}
