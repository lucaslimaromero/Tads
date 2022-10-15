# Implementando uma Árvore Binária

- Podemos realizar as seguintes operações:

- Criação da árvore
- Destruição da árvore

- Inserção de um elemento
- Remoção de um elemento

- Acesso a um elemento

. Essas operações dependem do tipo de alocação de memória usada:
- Estática (heap)
- Dinâmica (lista encadeada)

# Alocação Estática (HEAP)
- Uso de um array
- Usa 2 funções para retornar a posição dos filhos à esquerda e à direita de um pai

FILHO_ESQ(PAI) = 2 * PAI + 1
FILHO_DIR(PAI) = 2 * PAI + 2

- PROBLEMA: Eu devo saber o tamanho da árvore, e quando a árvore é completa, pois senão sobrará espaços dos vetores vazios
Logo muitos espaços alocados sem serem utilizados

# Alocação Dinâmica (LISTA ENCADEADA)
- Cada nó da árvore é tratado como um ponteiro alocado dinamicamente, a medida que os dados são inseridos

Cada nó será da forma:
______________________
| *esq | dado | *dir |
----------------------

# Implementação com Alocação dinâmica:
- Para guardar o primeiro nó da lista, usaremos um ponteiro para ponteiro, para facilitar caso quisermos mudar quem é a raiz da árvore
ArvBin* raiz;