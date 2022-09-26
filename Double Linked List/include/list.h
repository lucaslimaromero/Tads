#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

typedef struct _doubly_node DoublyNode, Node; // Dois apelidos para as mesmas coisas, para simplificar ainda mais
typedef struct _doubly_linked_list DoublyLinkedList, List;

// Assinatura das Funções do TAD

// Criação do nó
Node *Node_create(int val);

// Criação da Lista
List *List_create();

// Destruição da lista
void List_destroy(List **L_ref);

// Verifica se a Lista está vazia
bool List_is_empty(const List *L);

// Adiciona no início
void List_add_first(List *L, int val);
// Função de inserção na cauda
void List_add_last(List *L, int val);

// Função de impressão 
void List_print(const List *L);

// Função de impressão invertida
void List_inverted_print(const List *L);

// Função de Remoção de elementos da lista
void List_remove(List *L, int val);

//******************************* FIM DO HEADER DO TAD *******************************//

#endif