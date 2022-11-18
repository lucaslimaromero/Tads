#ifndef __BINARY_TREE1__H__
#define __BINARY_TREE1__H__

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

#include<stdbool.h>

// Struct de cada nó

typedef struct _node Node;
typedef struct _node *ArvBin; // Um ponteiro para um nó será apelidado de ArvBin

// Na função principal, será criado um ponteiro para esse ponteiro para nó: 

// Criação de um nó
Node *ArvBin_Node_create(int value);

// Criação da Árvore:
ArvBin *ArvBin_create();

// Destruição de cada nó
void Node_destroy(Node *node);
// Destruição da Árvore (desalocação dinâmica da raiz)
void ArvBin_destroy(ArvBin *raiz);

// Verifica se a árvore está vazia (1)
bool ArvBin_is_empty(ArvBin *raiz);

// Altura da árvore
int ArvBin_height(ArvBin *raiz);

// Quantidade de nós
int ArvBin_amount_nodes(ArvBin *raiz);

// Percorrendo uma Árvore Binária

// Pré-Ordem: RAIZ - ESQUERDA - DIREITA
void ArvBin_preOrdem(ArvBin *raiz);

// Em-Ordem: ESQUERDA - RAIZ - DIREITA
void ArvBin_emOrdem(ArvBin *raiz);

// Pós-Ordem: ESQUERDA - DIREITA - RAIZ 
void ArvBin_posOrdem(ArvBin *raiz);

// Inserção de um valor na árvore
bool ArvBin_insert(ArvBin *raiz, int value); // Retorna 1 se foi efetuada a operação, e 0 se o elemento já existe ou se não alocou

// Remoção de um valor da árvore (sem valores repetidos)
bool ArvBin_remove(ArvBin *raiz, int value); // Busca o nó a ser removido

//*************************************************************************************//

#endif  //!__BINARY_TREE1__H__