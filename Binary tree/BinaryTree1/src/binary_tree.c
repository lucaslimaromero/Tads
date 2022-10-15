#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Implementação do nó 

typedef struct _node{
    int info; // Informação que ele carrega
    struct _node *esq; // Endereço do nó à sua esquerda
    struct _node *dir; // Endereço do nó à sua direita
} Node; // Apelido para o struct _node = Node



