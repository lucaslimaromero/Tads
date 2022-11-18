#include <stdio.h>
#include <stdlib.h>
#include "binary_tree1.h"

// Estrutura de cada nó da árvore
typedef struct _node{
    int info; // Dado guardado por cada nó
    struct _node *esq; // Ponteiro que aponta para o nó da esquerda
    struct _node *dir; // Ponteiro que aponta para o nó da direita
} Node; // Apelido para o struct _node = Node

// Criação da Árvore: cria a raiz da árvore que é um ponteiro para ArvBin (ponteiro para ponteiro de nó)
ArvBin *ArvBin_create(){
    ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if(raiz != NULL){ // Caso a alocação deu certo
        *raiz = NULL; // O conteúdo da raiz, que é o endereço do primeiro nó é NULO
    }

    return raiz;
}

// Destruição de cada nó: recebe o ponteiro para o nó a ser desalocado
void Node_destroy(Node *node){ // Libera cada nó dado a raiz da árvore
    if(node != NULL){ // Condição de retorno da recursão, quando um nó não tem mais filhos
        return; // Se node é uma folha ele retorna
    }
    // Recursão: a função é executada até encontrar um nó NULO, após isso ocorre um desempilhamento dessas funções

    Node_destroy(node->esq); // Descendo na sub-árvore da esquerda
    Node_destroy(node->dir); // Depois para a direita

    // O nó só é liberado, caso o nó da da sua esquerda e o da sua direita já tenham sido liberados

    free(node);
    node = NULL;
}

// Destruição da Árvore: recebe o ponteiro do ponteiro para o primeiro nó da árvore
void ArvBin_destroy(ArvBin *raiz){
    if(raiz == NULL){
        return; // Erro na alocação da árvore
    }

    Node_destroy(*raiz); // O conteúdo de raiz, é o endereço para o primeiro nó
    free(raiz);
}

// Verifica se a árvore está vazia, retorna 1 caso sim ou caso a árvore não tenha sido alocada
bool ArvBin_is_empty(ArvBin *raiz){
    if(raiz == NULL){
        return 1; // Erro na alocação da árvore
    }
    if(*raiz == NULL){
        return 1; // Caso a raiz não tenha nós, ela está vazia, logo retorna verdadeiro (1)
    }
    return 0;
}

// Altura da árvore
int ArvBin_height(ArvBin *raiz){
    if(raiz == NULL){
        return 0; // Erro na alocação da árvore
    }
    if(*raiz == NULL){
        return 0; // Caso a raiz não tenha nós ela e está vazia, ou se é um nó folha, retorna-se uma altura 0
    }

    // Percorro a sub-árvore da esquerda e da direita
    int altura_esq = ArvBin_height(&((*raiz)->esq)); // A notação (&((*raiz)->esq)) significa o endereço de memória do nó a esquerda do nó
    int altura_dir = ArvBin_height(&((*raiz)->dir)); 

    // A altura final da árvore será sempre a altura da maior sub-árvore
    if(altura_esq > altura_dir){
        return (altura_esq + 1); // Somo 1 à medida em que subo na árvore
    }
    else{
        return (altura_dir + 1);
    }
}

// Quantidade de nós da árvore
int ArvBin_amount_nodes(ArvBin *raiz){
    if(raiz == NULL){
        return 0; // Erro na alocação da árvore
    }
    if(*raiz == NULL){
        return 0; // Caso a raiz não tenha nós ela e está vazia ou seja um nó folha, retorna 0 nós
    }

    int altura_esq = ArvBin_amount_nodes(&((*raiz)->esq));
    int altura_dir = ArvBin_amount_nodes(&((*raiz)->dir));

    return (altura_esq + altura_dir + 1);
}

// Percorrendo a árvore em pré-Ordem: RAIZ, FILHO DA ESQUERDA, FILHO DA DIREITA
void ArvBin_preOrdem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        printf("%d\n", (*raiz)->info); // RAIZ
        ArvBin_preOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_preOrdem(&((*raiz)->dir)); // DIREITA
    }
}

// Percorrendo a árvore em-Ordem: FILHO DA ESQUERDA, RAIZ, FILHO DA DIREITA
void ArvBin_preOrdem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        ArvBin_preOrdem(&((*raiz)->esq)); // ESQUERDA
        printf("%d\n", (*raiz)->info); // RAIZ
        ArvBin_preOrdem(&((*raiz)->dir)); // DIREITA
    }
}

// Percorrendo a árvore em pós-Ordem: FILHO DA ESQUERDA, FILHO DA DIREITA, RAIZ
void ArvBin_preOrdem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        ArvBin_preOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_preOrdem(&((*raiz)->dir)); // DIREITA
        printf("%d\n", (*raiz)->info); // RAIZ
    }
}