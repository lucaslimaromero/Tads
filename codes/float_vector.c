#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***************************** INTERFACE PRIVADA *****************************/
struct _float_vector{
    int capacity;
    int size;
    float *data;
};

bool _FloatVector_isFull(const FloatVector *vec){ // Padrão da sintaxe de funções privadas: _Função
    return vec->size == vec->capacity;
}

/***************************** IMPLEMENTAÇÃO DA INTERFACE PÚBLICA *****************************/

FloatVector *FloatVector_create(int capacity){

    FloatVector *vec = (FloatVector *) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float *) calloc(capacity, sizeof(float));

    return vec;
}

void FloatVector_destroy(FloatVector  **vec_ref){ // vec_ref é o endereço de vec
    FloatVector *vec = *vec_ref; // vec é o conteúdo de vec_ref
    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void FloatVector_append(FloatVector *vec, float val){
    if(_FloatVector_isFull(vec)){
        fprintf(stderr, "ERROR in 'append'\n"); //stderr é a saída padrão de erro
        fprintf(stderr, "Vector is full\n"); 
        exit(EXIT_FAILURE); // macro no C que indica falha
    }

    vec->data[vec->size++] = val;
}

void FloatVector_print(const FloatVector *vec){ // função de leitura
    puts("---------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);

    for(int i = 0; i < vec->size; i++){
        printf("[%d] = %f\n", i, vec->data[i]);
    }
    puts("---------------------\n");
}

int FloatVector_size(const FloatVector *vec){
    return vec->size;
}

int FloatVector_capacity(const FloatVector *vec){
    return vec->capacity;
}

float FloatVector_at(const FloatVector *vec, int index){
    if (index < 0 || index >= vec->size){ // segurança e menos eficiência (é um trade off)
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index[%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}

float FloatVector_get(const FloatVector *vec, int index){ // eficiência mas sem segurança
    return vec->data[index];
}

