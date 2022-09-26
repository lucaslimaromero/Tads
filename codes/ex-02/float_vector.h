#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct _float_vector FloatVector;

//Assinatura das funções
// As funções que manipulam FloatVector recebem esse nome na frente por padrão

FloatVector *FloatVector_create(int capacity); // alocação da memória heap contínua para o vetor
void FloatVector_destroy(FloatVector **vec_ref); // desaloca/free no vetor  
int FloatVector_size(const FloatVector *vec); // retorna o tamanho do vetor
int FloatVector_capacity(const FloatVector *vec); // retorna a capacidade do vetor

float FloatVector_at(const FloatVector *vec, int index); // retorna o elemento do indice index com bound checked
float FloatVector_get(const FloatVector *vec, int index); // retorna o elemento do indice index

void FloatVector_append(FloatVector *vec, float val); // adiciona val no final do vetor, dá erro se o vetor estiver cheio
void FloatVector_set(FloatVector *vec, int index, float val); // atribui val no index 
void FloatVector_print(const FloatVector *vec); // imprime todos os elementos do vetor

#endif