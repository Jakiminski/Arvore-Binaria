#include "header.h"
using namespace std;

    int bstCountNode(TNode* node){

        int counter = 0, left = 0, right = 0;
        if (node!=NULL){
            // PASSO BASE
            counter = 1;
            //PASSOS RECURSIVOS
            left = bstCountNode(node->left); // 'counter' de node->left
            right = bstCountNode(node->right); // 'counter' de node->right
        }
        counter += (left + right);
        return counter;

    }

    int bstCountLeaf(TNode* node){

        int counter = 0, left = 0, right = 0;
        if (node!=NULL){
            if (bstNodeIsLeaf(node)){
                // PASSO BASE
                counter = 1;
            }else{
                // PASSO RECURSIVO
                left = bstCountLeaf(node->left);
                right = bstCountLeaf(node->right);
            }
        }
        counter += (left + right);
        return counter;

    }

    int bstCountNode1(TNode* node){

        int counter = 0, left = 0, right = 0;
        if (node!=NULL){
            // Determinar grau 1: apenas 1 filho
            int flag1 = bstNodeLeftSon(node); // Filho Esquerdo
            int flag2 = bstNodeRightSon(node); // Filho Direito


            // PASSO BASE
            if ((flag1 && !flag2)||(!flag1 && flag2)){
                counter++; // Apenas qnd o nó possui apenas 1 filho
            }

            // PASSO RECURSIVO
            // Procura nós de grau 1 nas subárvores
            if (flag1){
                left = bstCountNode1(node->left);
            }
            if(flag2){
                right = bstCountNode1(node->right);
            }
        }
        counter += (left + right);
        return counter;

    }


    int bstCountNode2(TNode* node){

        int counter = 0, left = 0, right = 0;
        if (node!=NULL){
            // Determinar grau 2: ambos os filhos
            int flag1 = bstNodeLeftSon(node); // Filho Esquerdo
            int flag2 = bstNodeRightSon(node); // Filho Direito


            // PASSO BASE
            if ((flag1 && flag2)){
                counter++; // Apenas qnd nó possui ambos os filhos
            }

            // PASSO RECURSIVO
            // Procura nós de grau 2 nas subárvores
            if (flag1){
                left = bstCountNode1(node->left);
            }
            if(flag2){
                right = bstCountNode1(node->right);
            }
        }
        counter += (left + right);
        return counter;

    }



    void* bstHigherElement(TNode* node){
        //Nas BSTs, o elemento maior fica sempre
        if (node!=NULL){
            if (node->right!=NULL){ // ... à direita do nó-pai
                // PASSO RECURSIVO
                return bstHigherElement(node->right);
            }
            else{
                // PASSO BASE
                return node->data;
            }
        }
        return NULL;

    }

    void* bstLowerElement(TNode* node){
        //Nas BSTs, o elemento menor fica sempre
        if (node!=NULL){
            if (node->left!=NULL){ // ... à esquerda do nó-pai
                // PASSO RECURSIVO
                return bstLowerElement(node->left);
            }
            else{
                // PASSO BASE
                return node->data;
            }
        }
        return NULL;

    }

    TNode* bstTreeInsert(TNode* tree,void* key,int(*cmp)(void*,void*)){

        if (tree!=NULL){
            int status = cmp(key,tree->data);
            // Procurar local ideal para um novo nó
            if (status<=0){
                // À esquerda
                tree->left = bstTreeInsert(tree->left,key,cmp);
            }else{
                //À direita
                tree->right = bstTreeInsert(tree->right,key,cmp);
            }
            return tree;
        }else{
            // Aloca nó na árvore
            TNode* node = new TNode;
            if (node!=NULL){
                node->data = key;  // atribui dado ao nó
                node->left = NULL; node->right = NULL; //Nó tipo FOLHA
                return node;
            }
        }
        return NULL;

    }
