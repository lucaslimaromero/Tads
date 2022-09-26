#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _snode{
    int val;
    struct _snode *next; // Não podemos colocar Node *next, pois o compilador lê de cima para baixo, e ainda não sabe o que é Node
} SNode;

typedef struct _linked_list{
    SNode *begin; // Ponteiro para o primeiro nó
    SNode *end; // Ponteiro para o último nó, utilizado na hora de adicionar na cauda da lista
    size_t size;
} LinkedList;

LinkedList *LinkedList_create(){ // Alocar dinamicamente a estrutura de linked list para que o atributo begin aponte para NULL
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList)); // Alocando o primeiro Nó (Lista em si)
    L->begin = NULL; // A lista tem apenas um elemente, logo o ponteiro que aponta para o próximo é null
    L->end = NULL;
    L->size = 0;

    return L;
}

void LinkedList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL; // Preciso do aux, pois ao dar free(p) eu perderia o p->next

    while(p != NULL){
        aux = p; // aux aponta para onde o p aponta (salvamos a posição)
        p = p->next; // avançamos uma posição
        free(aux);
    }
    free(L); // Desalocamos a lista em si

    *L_ref = NULL;
}

bool LinkedList_is_empty(const LinkedList *L){
    return (L->size == 0);
}

size_t LinkedList_size(const LinkedList *L){
     return L->size;

    // Caso eu não tenha o fator size na minha lista e eu tenha que contar
    // A complexidade dessa função é O(n), pois precisamos varrer toda a lista
    // size_t size = 0;
    // SNode *p = L->begin;
    // while(p != NULL){
    //     size++;
    //     p = p->next;
    // }

    // return size;
}


SNode *SNode_create(int val){ // Aloca um nó dinamicamente e atribui a ele um valor, bem como seta como NULL o ponteiro para o próximo elemento
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

// Função para adicionar na cabeça sem o *end
// void LinkedList_add_first(LinkedList *L, int val){ // Essa função é belíssima, pois conecta o nó criado com a struct lista cujo ponteiro passará a ser o endereço desse nó
//     SNode *p = SNode_create(val); // Criamos um nó genérico e atribuímos
//     p->next = L->begin; // Caso a lista esteja vazia, o L->begin será nulo, de modo que encaixará certinho
//     L->begin = p; // o próximo elemento do nó criado será o 2 elemento da lista se existir, e o L->begin passa a apontar para o mesmo Nó que p aponta 
// }

void LinkedList_add_first(LinkedList *L, int val){ // Essa função é belíssima, pois conecta o nó criado com a struct lista cujo ponteiro passará a ser o endereço desse nó
    SNode *p = SNode_create(val);
    p->next = L->begin; // O ponteiro do nó adicionado agora aponta para o mesmo lugar que L->begin apontava

    if(LinkedList_is_empty(L)){
        L->end = p;
    }
    L->begin = p; // L->begin passa a apontar para o novo Nó
    L->size++;
}


void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = SNode_create(val);
    if(LinkedList_is_empty(L)){ // Se a lista estiver vazia
        L->begin = q;
    }
    else{
        SNode *p = L->begin; // p é um ponteiro auxiliar que aponta para um nó e começa sendo no primeiro no, apontado pelo L->begin

        while(p->next != NULL){ // Enquanto o p->next não for nulo, enquanto não é o último nó eu avanço no p
            p = p->next;
        }
        // Aqui p aponta para o último nó, sendo nele que queremos grudar nosso novo elemento
        // Agora, o p->next que era nulo passa a apontar para o novo nó criado e inserido
        p->next = q;
    }
    L->size++;
}

void LinkedList_add_last_fast(LinkedList *L, int val){
    SNode *q = SNode_create(val);

    if(LinkedList_is_empty(L)){ // Lista vazia - O primeiro e o último elemento são os mesmos
        L->begin = q;
        L->end = q;
    }
    else{ // Lista não vazia
        L->end->next = q; // Acessando o ponteiro next do último nó e colocando como o novo nó
        L->end = L->end->next; // Estou atualizando o ponteiro que aponta para o final da lista, agora apontando para o último nó recém-adicionado
    }
    L->size++;
}

void LinkedList_remove(LinkedList *L, int val){

    // Caso 1: Cabeça
    if(!LinkedList_is_empty(L)){ // Se a lista não está vazia
        SNode *pos = L->begin;
        if(L->begin->val == val){ // Se o elemento a ser retirado estiver na cabeça da lista
            
            L->begin = L->begin->next;
    
            if(L->end == pos){ // A lista possui apenas um elemento? 
                L->end = NULL;
            }
            free(pos);
        }
        // Não podemos implementar um else if val no fim da lista, pois nosso algoritmo quer retirar a primeira aparição do elemento
        // Dessa forma, é preciso verificar se sua única aparição é no final antes de retirá-lo    
        // Caso 2: Meio - Vamos usar dois ponteiros para Nós, um que aponte para o Nó a ser removido, e o outro para o nó anterior a ele
        else{
            pos = L->begin->next;
            SNode *prev = L->begin;

            while(pos != NULL && pos->val != val){ // Enquanto houver elementos na lista e enquanto não encontrar o elemento val, percorre-se a lista
                prev = prev->next; // prev = prev->next
                pos = pos->next;
                
            }
            // Consertando o encadeamento
            if(pos != NULL){ // Quer dizer que um nó de valor val foi encontrado, e pos aponta para ele nesse momento do código
                prev->next = pos->next;

                // Caso 3: Final da lista
                if(pos->next == NULL){ // Se o pos parou no último elemento da lista
                    L->end = prev;
                }
            }
            
            free(pos);
        }
        L->size--;
    }
}

void LinkedList_remove_new(LinkedList *L, int val){
    if(!LinkedList_is_empty(L)){
        SNode *pos = L->begin;
        SNode *prev = NULL;

        while (pos != NULL && pos->val != val){
            prev = pos; // Não pode ser prev = prev->next; pois o prev next pode ser NULL, no caso de ser o início da lista
            pos = pos->next;
        }

        if (pos != NULL){ // Se achou um elemento
            if(L->end == pos){ // Encontrou no final
                L->end = prev;
            }
            if(L->begin == pos){ // Encontrou no início
                L->begin = pos->next;
            }
            else{
                prev->next = pos->next;
            }

            free(pos);
        }
        L->size--;
    }
}

int LinkedList_first_val(const LinkedList *L){
    if(LinkedList_is_empty(L)){
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\n");   
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else{
        return L->begin->val;
    }  
}

int LinkedList_get_val(const LinkedList *L, int index){
    if(LinkedList_is_empty(L)){
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");   
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else if(index < 0 || index >= L->size){
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");   
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within: [0, %lu]\n", L->size - 1);
        exit(EXIT_FAILURE);
    }
    else{
        SNode *p = L->begin;
        for (int i = 0; i < index; i++){
            p = p->next;
        }
        return p->val; // Retorna o valor no index solicitado
    }
} 

int LinkedList_last_val(const LinkedList *L){
    if(LinkedList_is_empty(L)){
        fprintf(stderr, "ERROR in 'LinkedList_last_val'\n");   
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->end->val;
}

void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;

    printf("L -> ");
    while(p != NULL){ // Enquanto p estiver apontando para um Nó válido
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");

    if(L->end == NULL){ // Lista vazia
        printf("L->end = NULL\n");
    }
    else{
        printf("L->end = %d\n", L->end->val);
        printf("List Size: %lu\n", L->size);
    }
    puts("");
}

