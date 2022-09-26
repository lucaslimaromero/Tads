#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>
 //size_t = unsigned long long || A referência é %zd or %zu

typedef struct _static_stack{
    int *data; // ponteiro para o valor que a pilha armazena
    size_t capacity;
    int top;
} StaticStack;

StaticStack *StaticStack_create(size_t capacity){
    StaticStack *S = (StaticStack *) calloc(1, sizeof(StaticStack));
    S->capacity = capacity;
    S->top = -1;
    S->data = (int *) calloc(capacity, sizeof(int));

    return S;
}

// void StaticStack_destroy