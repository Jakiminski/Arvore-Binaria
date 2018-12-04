#include "header.h"
using namespace std;

    void bstTreePreOrder(TNode* node,void(*visit)(void*)){

        if (node!=NULL){
            visit(node->data);    // PASSO BASE
            bstTreePreOrder(node->left,visit); // PASSO RECURSIVO
            bstTreePreOrder(node->right,visit);// PASSO RECURSIVO
        }

    }

    void bstTreeInOrder(TNode* node,void(*visit)(void*)){

        if (node!=NULL){
            bstTreeInOrder(node->left,visit);   // PASSO RECURSIVO
            visit(node->data);    // PASSO BASE
            bstTreeInOrder(node->right,visit);  // PASSO RECURSIVO
        }

    }

    void bstTreePostOrder(TNode* node,void(*visit)(void*)){

        if (node!=NULL){
            bstTreePostOrder(node->left,visit); // PASSO RECURSIVO
            bstTreePostOrder(node->right,visit);// PASSO RECURSIVO
            visit(node->data);    // PASSO BASE
        }

    }

    void* bstTreeQuery(TNode* node,void* key,int(*cmp)(void*,void*)){

        if (node!=NULL){
            int status = cmp(key,node->data);

            if (status<0){
                // PASSO RECURSIVO
                return bstTreeQuery(node->left,key,cmp);
            }else if (status>0){
                // PASSO RECURSIVO
                return bstTreeQuery(node->right,key,cmp);
            }else if(status==0){
                // PASSO BASE
                return node->data;
            }
        }
        return NULL;

    }

    TNode* bstTreeRemove(TNode* node,void* key,void* *data,int(*cmp)(void*,void*)){

        TNode* aux;
        void *data2;

        if(node!=NULL){
            int status = cmp(key, node->data);
            if(status<0){
                // PASSO RECURSIVO
                node->left = bstTreeRemove(node->left, key, data, cmp);
                return node;
            }
            else if(status>0){
                // PASSO RECURSIVO
                node->right = bstTreeRemove(node->right, key, data, cmp);
                return node;
            }
            else if(status==0){
                // PASSO BASE
                *data = node->data;

                if(node->left==NULL && node->right==NULL){
                    // FOLHA
                    delete node;
                    return NULL;

                }else if(node->left!=NULL && node->right==NULL){
                    // SUBARVORE ESQUERDA
                    aux = node->left;
                    delete node;
                    return aux;

                }else if(node->left==NULL && node->right!=NULL){
                    // SUBARVORE DIREITA
                    aux = node->right;
                    delete node;
                    return aux;

                }else if(node->left!=NULL && node->right!=NULL){
                    // POSSUI AMBAS AS SUBARVORES
                    node->data = bstHigherElement(node->right); // Maior filho da árvore
                    bstTreeRemove(node->right, node->data, &data2, cmp);
                    node->right = NULL;
                    return node;
                }
            }
        }
        cerr<< "\nWARNING:\tNó não removido, possivelmente não encontrado ou não existe\n";
        return NULL;
    }

