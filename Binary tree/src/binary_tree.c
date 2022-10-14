#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

typedef struct _item{
    int cod;
} Item;

typedef struct _node{
    Item item;
    struct _node *left;
    struct _node *right;
} Node;

// Criação de um nó especial raiz que aponta para o início da árvore

ArvBin *ArvBin_create(){
    // Criação de um ponteiro para o tipo ArvBin
    // ArvBin é um ponteiro que aponta para nós
    // Logo, raiz é um ponteiro de ponteiro
    ArvBin *root = (ArvBin*) calloc(1, sizeof(ArvBin));
    if(root != NULL){
        *root = NULL;
    }
    

    return root;
}

