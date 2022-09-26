# LISTAS  ENCADEADAS/LIGADAS SIMPLES (LINKED LISTS)

*Motivação*: "Sempre desenhar a estrutura de dados antes de implementá-la"

- Surge de um problema nos vetores/arrays

    => E se quisessemos aumentar o tamanho de um array?

    . Poderiamos usar realloc, mas é uma função perigosa (PERIGOSO) -> Uso operacional de memória grande pelo fato de deletar a antiga e alocar conteúdo em um novo espaço de memória na Heap. 
    . Poderiamos criar um novo array com um tamanho maior e copiar os elementos antigos (INEFICIENTE)
    . Criar um vetor grande o suficiente para sempre ter espaço de inserir um novo aluno (SE CHEGAR NO FINAL)

- Surge outro problema:

    . E se quisermos colocar o novo aluno no começo (pior cenário) ou meio do array, teríamos q deslocar todos em +1 no indice
    . Na hora de remover, aconteceria algo parecido, mas com -1 no indice

*Conceito de Lista Encadeada*: Estrutura de dados em que cada elemento é um nó (NODE) - NÃO CONTÍGUOS NA MEMÓRIA (esparsos)

- É uma representação de uma sequência de elementos/objetos na memória do computador.
- Os elementos (Nodes) são armazenados em posiçãoes quaisquer da memória e são ligados por *ponteiros*
- Elementos consecutivos *NÃO* ficam necessariamente em posições consecutivas na memória

L -> Nó 1 {int ou qualquer outro objeto; *ponteiro p/ o prox} -> Nó 2 {int; *ponteiro p/ o prox} -> ... -> Nó N {int; *ponteiro = _NULL_}

*Outras Listas*:

- _Circulares:_ o ponteiro do último elemento é para o primeiro elemento da lista
- _Listas Duplamentes Encadeadas:_ além do ponteiro para o próximo tem o ponteiro para o anterior, o valor do ponteiro do anterior ao primeiro é NULL,
igualmente ao proximo do ultimo
- _Listas Circulares Duplamente Encadeadas:_ Agora o ponteiro do anterior do primeiro elemento aponta para o último, e o proximo do ultimo aponta para o primeiro

# Implementação Comum

. Uma lista encadeada é uma sequência de Nós
. Se o ponteiro L aponta para o primeiro Nó, podemos dizer que L é uma lista

# Implementação Utilizada

. Há um tipo próprio de struct Lista que guardará um ponteiro para o seu início (elemento de cabeça)
. Dá liberdade para colocar informações importantes da lista nessa nova struct 
. Nos dá flexibilidade

typedef struct _snode{
    int val; *Contéúdo do Nó*
    struct _snode *next; *Ponteiro que aponta para o próximo nó*
} SNode;
 
typedef struct _linked_list {
    Node *begin; 
    int size;
} LinkedList;

L -> begin ->  Nó 1 {int ou qualquer outro objeto; *ponteiro p/ o prox}

# Lógica de Impressão dos Elementos da Lista

enquanto a lista não chega ao fim (p != NULL)
- imprimir os dados apontados por p (p->val)
- mover p para o prox elemento da lista (p = p->next)