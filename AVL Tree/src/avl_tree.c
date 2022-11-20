// Implementação do TAD

#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

// Implementação do nó 

typedef struct _node{
    int info; // Informação que ele carrega
    int alt; // Altura da sub-árvore, cujo pai é o nó em questão para calcular o fb de cada nó
    struct _node *esq; // Endereço do nó à sua esquerda
    struct _node *dir; // Endereço do nó à sua direita
} Node; // Apelido para o struct _node = Node

Node *ArvBin_Node_create(int value){
    Node *node = (Node*) malloc(sizeof(Node));

    if(node == NULL){ // Verifica se deu certo a alocação
        return NULL;
    }

    node->info = value;
    node->alt = 0;
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

ArvBin *ArvBin_create(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL){ // Caso a alocação tenha dado certo
        *raiz = NULL; // Estamos colocando o conteúdo desse ponteiro de ponteiro como nulo
    }
    return raiz;
}
void Node_destroy(Node *node){
    if(node == NULL){ // Se o endereço do nó já estiver nulo, pode-se parar a função
        return;
    }
    // Recursão: a função é executada até encontrar um nó NULO, após isso ocorre um desempilhamento dessas funções

    Node_destroy(node->esq);
    Node_destroy(node->dir);

    // O nó só é liberado, caso o nó da da sua esquerda e o da sua direita já tenham sido liberados
    free(node);
    node = NULL;
}

void ArvBin_destroy(ArvBin *raiz){
    if(raiz == NULL){ // Se o endereço raiz for nulo
        return; // A função é parada
    }
    Node_destroy(*raiz); // Envia-se o conteúdo de raiz (endereço de memória de ArvBin, que é o nó inicial da árvore)
    free(raiz); // Libera a raiz
}

bool ArvBin_is_empty(ArvBin *raiz){ // Conteúdo da raiz = endereço de memória para o primeiro nó
    if(raiz == NULL){ // Caso a memória não tenha sido alocada corretamente
        return 1;
    }
    if(*raiz == NULL){ // Caso a árvore não tenha nenhum nó
        return 1;
    }
    return 0; // Senão, a árvore não está vazia
}

int ArvBin_height(ArvBin *raiz){
    if(ArvBin_is_empty(raiz)){ // Condição de parada
        // Se a árvore estiver vazia, a sua alt é 0
        return 0;
    }

    int left_height = ArvBin_height(&((*raiz)->esq));
    int right_height = ArvBin_height(&((*raiz)->dir));

    // A alt da árvore é dada pela maior quantidade de arestas
    if(left_height > right_height){
        return (left_height + 1);
    }
    else{
        return (right_height + 1);
    }
}

int ArvBin_amount_nodes(ArvBin *raiz){
    if(ArvBin_is_empty(raiz)){ // Condição de parada
        return 0;
    }
    int left_height = ArvBin_amount_nodes(&((*raiz)->esq));
    int right_height = ArvBin_amount_nodes(&((*raiz)->dir));

    return (left_height + right_height + 1); // + 1 é o pai
}

void ArvBin_preOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        printf("%d\n", (*raiz)->info); // RAIZ
        ArvBin_preOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_preOrdem(&((*raiz)->dir)); // DIREITA
    }
}

void ArvBin_emOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        ArvBin_emOrdem(&((*raiz)->esq)); // ESQUERDA
        printf("%d\n", (*raiz)->info); // RAIZ
        ArvBin_emOrdem(&((*raiz)->dir)); // DIREITA
    }
}

void ArvBin_posOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        ArvBin_posOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_posOrdem(&((*raiz)->dir)); // DIREITA
        printf("%d\n", (*raiz)->info); // RAIZ
    }
}

// ------------- Funções Auxiliares ------------- //
int alt_node(Node *node){ // Recebe um nó e devolve a alt dele
    if(node == NULL) // Se o nó for nulo (não existir), a alt dele será considerada -1
        return -1;
    else
        return node->alt;
}

int fatorBalanceamento_node(Node *node){ // Quero saber a diferença em módulo das alts dos filhos do nó
    return labs(alt_node(node->esq) - alt_node(node->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}
// -------------------------------------------- //

// Função de Rotação LL
void ArvBin_RotationLL(ArvBin *raiz){
    Node *node; // Nó auxiliar para guardar o endereço do filho da esquerda
    node = (*raiz)->esq;
    (*raiz)->esq = node->dir;
    node->dir = *raiz;

    // Recalculando as alts
    (*raiz)->alt = maior(alt_node((*raiz)->esq), alt_node((*raiz)->dir)) + 1;
    node->alt = maior(alt_node(node->esq), (*raiz)->alt) + 1;

    *raiz = node;
}

// Função de Rotação RR
void ArvBin_RotationRR(ArvBin *raiz){
    Node *node; // Nó auxiliar para guardar o endereço do filho da direita
    node = (*raiz)->dir;
    (*raiz)->dir = node->esq;
    node->esq = *raiz;

    // Recalculando as alts
    (*raiz)->alt = maior(alt_node((*raiz)->esq), alt_node((*raiz)->dir)) + 1;
    node->alt = maior(alt_node(node->esq), (*raiz)->alt) + 1;

    *raiz = node;
}

void ArvBin_RotationLR(ArvBin *raiz){
    ArvBin_RotationRR(&(*raiz)->esq);
    ArvBin_RotationLL(raiz);
}

void ArvBin_RotationRL(ArvBin *raiz){
    ArvBin_RotationLL(&(*raiz)->dir);
    ArvBin_RotationRR(raiz);
}

bool ArvBin_insert(ArvBin *raiz, int value){ // Sempre a inserção será numa folha
    int res;

    // Árvore vazia ou nó folha
    if(*raiz == NULL){ 
        Node *novo = ArvBin_Node_create(value);
        if(novo == NULL)
            return 0;
        
        *raiz = novo;
        return 1;
    }

    Node *atual = *raiz;
    if(value < atual->info){
        if((res = ArvBin_insert(&(atual->esq), value)) == 1){
            if(fatorBalanceamento_node(atual) >= 2){
                if(value < (*raiz)->esq->info){
                    ArvBin_RotationLL(raiz);
                }
                else{
                    ArvBin_RotationLR(raiz);
                }
            }
        }
    }
    else{
        if(value > atual->info){
            if((res = ArvBin_insert(&(atual->dir), value)) == 1){
                if(fatorBalanceamento_node(atual) >= 2){
                    if((*raiz)->dir->info < value){
                        ArvBin_RotationRR(raiz);
                    }
                    else{
                        ArvBin_RotationRL(raiz);
                    }
                }
            }
        }
        else{
            printf("Valor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_node(atual->esq), alt_node(atual->dir)) + 1;

    return res;
}

Node *procuraMenor(Node *atual){
    Node *no1 = atual;
    Node *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

bool ArvBin_remove(ArvBin *raiz, int value){
	if(*raiz == NULL){// value nao existe
	    printf("Esse valor nao existe!\n");
	    return 0;
	}

    int res;
	if(value < (*raiz)->info){
	    if((res = ArvBin_remove(&(*raiz)->esq,value)) == 1){
            if(fatorBalanceamento_node(*raiz) >= 2){
                if(alt_node((*raiz)->dir->esq) <= alt_node((*raiz)->dir->dir))
                    ArvBin_RotationRR(raiz);
                else
                    ArvBin_RotationRL(raiz);
            }
	    }
	}

	if((*raiz)->info < value){
	    if((res = ArvBin_remove(&(*raiz)->dir, value)) == 1){
            if(fatorBalanceamento_node(*raiz) >= 2){
                if(alt_node((*raiz)->esq->dir) <= alt_node((*raiz)->esq->esq) )
                    ArvBin_RotationLL(raiz);
                else
                    ArvBin_RotationLR(raiz);
            }
	    }
	}

	if((*raiz)->info == value){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// no tem 1 filho ou nenhum
			Node *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // no tem 2 filhos
			Node* temp = procuraMenor((*raiz)->dir);
			(*raiz)->info = temp->info;
			ArvBin_remove(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_node(*raiz) >= 2){
				if(alt_node((*raiz)->esq->dir) <= alt_node((*raiz)->esq->esq))
					ArvBin_RotationLL(raiz);
				else
					ArvBin_RotationLR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->alt = maior(alt_node((*raiz)->esq),alt_node((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->alt = maior(alt_node((*raiz)->esq),alt_node((*raiz)->dir)) + 1;

	return res;
}

bool ArvBin_consult(ArvBin *raiz, int value){
    if(raiz == NULL){
        return 0;
    }
    Node *atual = *raiz;
    while(atual != NULL){
        if(atual->info == value){
            return 1;
        }
        if(value > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}
