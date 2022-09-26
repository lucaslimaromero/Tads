#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(size_t capacity);
void StaticStack_destroy(StaticStack **S_ref);

bool StaticStack_is_empty(const StaticStack *S); // retorna 1 se estiver vazia (top == -1)
bool StaticStack_is_full(const StaticStack *S); // retorna 1 se estiver cheia (top == capacity)

void StaticStack_push(StaticStack *S, int val); // A pilha será alterada, pois será adicionado um elemento do topo, portanto ele mudará
int StaticStack_peek(const StaticStack *S); // A função é de leitura e retornará apenas o elemento armazenado
int StaticStack_pop(StaticStack *S); // A pilha será alterada, pois perderá um elemento

#endif