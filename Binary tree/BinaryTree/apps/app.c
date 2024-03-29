#include "binary_tree.h"
#include <stdio.h>

int main(){

    // ArvBin *raiz; (ponteiro para ponteiro) - nó especial
    ArvBin *raiz = ArvBin_create(); // Criação no programa principal, da raiz da árvore (a raiz é um ponteiro para ponteiro)
    // A variável raiz, guarda o endereço de um endereço 
    int valor;

    for(int i = 0; i < 3; i++){
        scanf("%d", &valor);
        if(ArvBin_insert(raiz, valor) == 0){
            printf("Erro na inserção");
        }
    }

    ArvBin_emOrdem(raiz);
    
    printf("Numero de Nos: %d", ArvBin_amount_nodes(raiz));
    printf("Existe o valor 3 na árvore? %d", ArvBin_consult(raiz, 3));

    return 0;
}