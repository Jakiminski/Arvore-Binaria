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

    /* LEMBRANDO COISAS �TEIS PARA A �RVORE DO TIPO DE PESQUISA BIN�RIA (BST - Binary Search Tree):

    1. O grau do n� de uma �rvore � determinado pela quantidade de filhos que ele possui:
        - Se o n� n�o possui "n�s-filhos" (grau 0), ele � dito 'folha';
        - Se possui n�-filho esquerdo e/ou direito, o grau � a quantidade de filhos (1 ou 2);
        - Se a �rvore for do tipo ESTRITAMENTE BIN�RIA, todos os n�s tem grau 0 ou 2 (sub�rvores e folhas, somente);

    2. Pelo m�todo de itera��o InOrder (Left,Roots,Right), os elementos est�o ordenados de forma crescente.

    3. Em uma �rvore ESTRITAMENTE BIN�RIA (de pesquisa ou n�o), a rela��o entre a quantidade de n�s e a altura d�-se por:

                           QNT de N�s(n)    Somatorio de N           ALTURA (H)
             w------------  1(2^0)           n = 2^0                    0
        w        w--------  2(2^1)           n = 2^0+2^1                1

     w    w    w    w-----  4(2^2)           n = 2^0+2^1+2^2            2

    w w  w w  w w  w w----  8(2^3)           n = 2^0+2^1+2^2+2^3        3
                                                  ( . . . )
    ( . . . )      -------  2^h              n = 2^0+2^1+(...)+2^h      H
    (altura a partir do ZERO)                   = 2^(h+1) -1       -------> QNT DE N�s em uma �rvore qqr

        N = 2^(H+1) -1
        N + 1 = 2^(H+1)  ---> log2(N+1) = H+1 ---> H = log2(N+1) -1
        OU
        N = 2^(H+1) -1
        N + 1 = 2^(H+1)  ---> (N+1)/2 = 2^H ---> H = log2((N+1)/2) ---> H = log2(N+1) - log2(2)
                                                                H = log2(N+1) -1 aproximadamente.

        Valor exato (em n�meros inteiros)
        H = (int) log2(N+1) - 1, por�m, arredondado para cima (fun��o teto: 'ceil')

        logo, H = ceil(log2(N+1) -1)


    RESUMINDO:      N = 2^(H+1) -1    <----->  H = ceil(log2(N+1) -1)

    */

////////// OPERA��ES /////
//////////////////////////////////////

        //1.1. Criar/Destruir Estrutura
    BSTree* bstCreate(void);
    int bstDestroy(BSTree* tree);
    //OK

        //1.2.  Utilit�rios I - Checa-n�s
    int bstTreeIsEmpty(BSTree* tree);// BSTree->root, BOOLEAN
    int bstNodeLeftSon(TNode* node); // BOOLEAN
    int bstNodeRightSon(TNode* node);// BOOLEAN
    int bstNodeIsLeaf(TNode* node);// Branch 0 - Folha, BOOLEAN
    int bstNodeBranch(TNode* node);// retorna Grau do n�, sen�o -1
    //OK

        //2.1  Utilit�rios II (passar BSTree->root)
    int bstCountNode(TNode* node);// Qnt. de n�s
    int bstCountLeaf(TNode* node);// Qnt. de folhas
    int bstCountNode1(TNode* node);// Qnt. de n�s de grau 1
    int bstCountNode2(TNode* node);// Qnt. de n�s de grau 2
    //int bstCountHeight(TNode* node);// Altura da �rvore/n�
    //int bstRecHeight(TNode* node,int h);// Recursividade a bstCountHeight(), requer altura (>=0)
    void* bstHigherElement(TNode* node);// Maior elemento da �rvore(int)
    void* bstLowerElement(TNode* node);// Maior elemento da �rvore(int)
    //OK

        //2.2  Inser��o - Instanciar n�
    TNode* bstTreeInsert(TNode* tree,void* key,int(*cmp)(void*,void*));//Inser��o n� tipo folha, compara valores
    //OK

        //3.1  Consulta (passar BSTree->root)
    void bstTreePreOrder(TNode* node,void(*visit)(void*));//Imprime �rvore: RAIZ-Esquerda-Direita
    void bstTreeInOrder(TNode* node,void(*visit)(void*));//Imprime �rvore: Esquerda-RAIZ-Direita
    void bstTreePostOrder(TNode* node,void(*visit)(void*));//Imprime �rvore: Esquerda-Direita-RAIZ
    void* bstTreeQuery(TNode* node,void* key,int(*cmp)(void*,void*));//Consulta elemento por chave
    //OK

        //3.2  Remo��o - Remove n� indicado (passar BSTree->root)
    TNode* bstTreeRemove(TNode* node,void* key,void* *data,int(*cmp)(void*,void*));
    //FALTA IMPLEMENTAR REMOVE

#endif // TREE_H

