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
No programa principal: 
ArvBin* raiz;

# Árvore Binária de Busca: 
-> Os nós a esquerda devem ser sempre menores que o nó pai
-> Os nós a direita devem ser sempre maiores que o nó pai
- Aplicações: Busca Binária, Análise de Expressões algébricas...

- Árvores desbalanceadas são aquelas que a porção direita ou esquerda é maior que a outra ponta

# Lógica de Inserção:
- Inserir um valor V:
1. Compare V com a raiz
2. V é menor que a raiz, vai para a sub-árvore da esquerda
3. V é maior, vai para a da direita
4. Aplique isso recursivamente

OBS.: Deve-se considerar o caso em que a árvore está vazia (*raiz == NULL) = O conteúdo da raiz (o valor que ArvBin aponta é nulo)

# Lógica de Remoção de um nó
-> Nó folha (Não afeta em nada o restante da árvore) -> Mais fácil
-> Nó com 1 filho
-> Nó com 2 filhos
-> Último nó de uma árvore
-> Árvore já vazia
