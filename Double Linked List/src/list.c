#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _doubly_node{
    int val;
    struct _doubly_node *next;
    struct _doubly_node *prev;
} DoublyNode, Node;

typedef struct _doubly_linked_list{
    Node *begin;
    Node *end;
    size_t size;
} DoublyLinkedList, List;

Node *Node_create(int val){
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}
List *List_create(){
    List *L = (List *) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void List_destroy(List **L_ref){
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = p;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

bool List_is_empty(const List *L){
    return L->size == 0; // Se estiver vazia retorna 1 (true)
}


// void List_add_first(List *L, int val){
//     Node *p = Node_create(val);

//     if(List_is_empty(L)){ // Lista vazia
//         L->begin = L->end = p;
//     }
//     else{ // Lista não vazia
//         p->next = L->begin;
//         L->begin->prev = p;
//         L->begin = p;
//     }

//     L->size++;
// }

void List_add_first(List *L, int val){
    Node *p = Node_create(val);
    p->next = L->begin; // Não atrapalha caso a lista estiver vazia e é crucial caso ela não esteja

    if(List_is_empty(L)){ // Lista vazia
        L->end = p;
    }
    else{ // Lista não vazia
        L->begin->prev = p; // Essa linha só pode ser executada se L->begin for NÃO NULO, ou seja, se a lista não tiver vazia
    }

    L->begin = p;
    L->size++;
}















//*************************** FIM DA IMPLEMENTAÇÃO DO TAD ********************//