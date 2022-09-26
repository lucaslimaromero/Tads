#ifndef LINKED_LIST_H
#define LINKED_LIST_H
 
#include <stdbool.h>
#include <stddef.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

// Função que cria um nó (aloca) e atribui a ele um valor inteiro, p ex.(val)
SNode *SNode_create(int val);

//Função que verifica se a lista está vazia (retorna 1 se tiver)
bool LinkedList_is_empty(const LinkedList *L);

//Função para criar a lista
LinkedList *LinkedList_create();

// Funções para desalocar a LinkedList
void LinkedList_destroy();

//Função para inserir na cabeça
void LinkedList_add_first(LinkedList *L, int val); // Inserção na cabeça (início) da lista

// Inserção na cauda (final) da lista
void LinkedList_add_last_slow(LinkedList *L, int val); // Lenta
void LinkedList_add_last_fast(LinkedList *L, int val); // Rápida

// Impressão dos Elementos da Lista
void LinkedList_print(const LinkedList *L);

// Função que remove a primeira aparição de determinado valor em uma lista
// A lógica é percorrer a lista, se ela não tiver vazia, até encontrar o elemento que aponta para esse valor, alterando o *next para o que o valor a ser retirado aponta
// Caso 1: Remoção na cabeça - criamos um SNode *p = L->begin, e L->begin = L->begin->next
void LinkedList_remove(LinkedList *L, int val);
void LinkedList_remove_new(LinkedList *L, int val);

// Função retorna o tamanho da lista
size_t LinkedList_size(const LinkedList *L);

// Função que retorna o primeiro valor
int LinkedList_first_val(const LinkedList *L);

// Função que retorna um valor num dado indice
int LinkedList_get_val(const LinkedList *L, int index);

// Função que retorna o valor final
int LinkedList_last_val(const LinkedList *L);


#endif