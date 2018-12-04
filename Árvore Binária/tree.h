#ifndef TREE_H
#define TREE_H

////////// ESTRUTURA /////
//////////////////////////////////////

    typedef struct _TREE_NODE{
        void* data;
        _TREE_NODE* left;
        _TREE_NODE* right;
    }TNode;

    typedef struct _TREE_ROOT{
        TNode* root;
    }BSTree;

    /* LEMBRANDO COISAS ÚTEIS PARA A ÁRVORE DO TIPO DE PESQUISA BINÁRIA (BST - Binary Search Tree):

    1. O grau do nó de uma árvore é determinado pela quantidade de filhos que ele possui:
        - Se o nó não possui "nós-filhos" (grau 0), ele é dito 'folha';
        - Se possui nó-filho esquerdo e/ou direito, o grau é a quantidade de filhos (1 ou 2);
        - Se a árvore for do tipo ESTRITAMENTE BINÁRIA, todos os nós tem grau 0 ou 2 (subárvores e folhas, somente);

    2. Pelo método de iteração InOrder (Left,Roots,Right), os elementos estão ordenados de forma crescente.

    3. Em uma árvore ESTRITAMENTE BINÁRIA (de pesquisa ou não), a relação entre a quantidade de nós e a altura dá-se por:

                           QNT de Nós(n)    Somatorio de N           ALTURA (H)
             w------------  1(2^0)           n = 2^0                    0
        w        w--------  2(2^1)           n = 2^0+2^1                1

     w    w    w    w-----  4(2^2)           n = 2^0+2^1+2^2            2

    w w  w w  w w  w w----  8(2^3)           n = 2^0+2^1+2^2+2^3        3
                                                  ( . . . )
    ( . . . )      -------  2^h              n = 2^0+2^1+(...)+2^h      H
    (altura a partir do ZERO)                   = 2^(h+1) -1       -------> QNT DE Nós em uma árvore qqr

        N = 2^(H+1) -1
        N + 1 = 2^(H+1)  ---> log2(N+1) = H+1 ---> H = log2(N+1) -1
        OU
        N = 2^(H+1) -1
        N + 1 = 2^(H+1)  ---> (N+1)/2 = 2^H ---> H = log2((N+1)/2) ---> H = log2(N+1) - log2(2)
                                                                H = log2(N+1) -1 aproximadamente.

        Valor exato (em números inteiros)
        H = (int) log2(N+1) - 1, porém, arredondado para cima (função teto: 'ceil')

        logo, H = ceil(log2(N+1) -1)


    RESUMINDO:      N = 2^(H+1) -1    <----->  H = ceil(log2(N+1) -1)

    */

////////// OPERAÇÕES /////
//////////////////////////////////////

        //1.1. Criar/Destruir Estrutura
    BSTree* bstCreate(void);
    int bstDestroy(BSTree* tree);
    //OK

        //1.2.  Utilitários I - Checa-nós
    int bstTreeIsEmpty(BSTree* tree);// BSTree->root, BOOLEAN
    int bstNodeLeftSon(TNode* node); // BOOLEAN
    int bstNodeRightSon(TNode* node);// BOOLEAN
    int bstNodeIsLeaf(TNode* node);// Branch 0 - Folha, BOOLEAN
    int bstNodeBranch(TNode* node);// retorna Grau do nó, senão -1
    //OK

        //2.1  Utilitários II (passar BSTree->root)
    int bstCountNode(TNode* node);// Qnt. de nós
    int bstCountLeaf(TNode* node);// Qnt. de folhas
    int bstCountNode1(TNode* node);// Qnt. de nós de grau 1
    int bstCountNode2(TNode* node);// Qnt. de nós de grau 2
    //int bstCountHeight(TNode* node);// Altura da árvore/nó
    //int bstRecHeight(TNode* node,int h);// Recursividade a bstCountHeight(), requer altura (>=0)
    void* bstHigherElement(TNode* node);// Maior elemento da árvore(int)
    void* bstLowerElement(TNode* node);// Maior elemento da árvore(int)
    //OK

        //2.2  Inserção - Instanciar nó
    TNode* bstTreeInsert(TNode* tree,void* key,int(*cmp)(void*,void*));//Inserção nó tipo folha, compara valores
    //OK

        //3.1  Consulta (passar BSTree->root)
    void bstTreePreOrder(TNode* node,void(*visit)(void*));//Imprime Árvore: RAIZ-Esquerda-Direita
    void bstTreeInOrder(TNode* node,void(*visit)(void*));//Imprime Árvore: Esquerda-RAIZ-Direita
    void bstTreePostOrder(TNode* node,void(*visit)(void*));//Imprime Árvore: Esquerda-Direita-RAIZ
    void* bstTreeQuery(TNode* node,void* key,int(*cmp)(void*,void*));//Consulta elemento por chave
    //OK

        //3.2  Remoção - Remove nó indicado (passar BSTree->root)
    TNode* bstTreeRemove(TNode* node,void* key,void* *data,int(*cmp)(void*,void*));
    //FALTA IMPLEMENTAR REMOVE

#endif // TREE_H

