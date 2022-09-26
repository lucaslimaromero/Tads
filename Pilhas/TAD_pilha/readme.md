# PILHAS - MOTIVAÇÃO

_Política de gerenciamento de elementos_: LIFO (Last in, First Out)
    - O último a entrar é o primeiro a sair

. Existem pilhas de qualquer coisa. Ex.: Livros.
. Para empilhar livros, sempre colocamos no topo.
. Se a pilha está vazia, seria colocar o primeiro elemento.
. Desemplilhar é retirar o elemento do topo.

*Definição*: Lista linear na qual as operações de inserção (push) e remoção (pop) são efetuadas sempre num mesmo extremo, denominado o _TOPO_ da pilha.

*Aplicações*:

*1*. Avaliação de Expressões: Ordem de execução das operações, qual é a preferência (ex.: multiplicação antes da soma);
*2*. Casamento de Parênteses: Checar se todo parênteses que abre tem um que fecha;
*3*. Conversão de Expressões;
*4*. Gerenciamento de Memória;
*5*. Backtracking Problems.

# TIPOS DE PILHAS (ESTÁTICA E DINÂMICA)

*ESTÁTICAS*: Implementadas com vetores (não significa que devem ser vetores estáticos, pois alocaremos dinamicamente, inclusive)

- O termo estático está relacionado à capacidade máxima "n" dessa pilha.

*Dinâmicas*: Implementadas com listas encadeadas, se não so.

# PILHAS ESTÁTICAS

. A pilha S[n], com n = 100, é S[0, ..., 100] e possui parte ocupada S[0, ..., top]
. O índice top = (guarda) [i] define o topo da pilha

. Pilha *vazia* se top == -1 (que seria uma notação inválida).
. Pilha *cheia* se top == n - 1.

*Empilhar* (PUSH) um elemento y: 
    . S[++top] = y (colocar um elemento sobre o topo da pilha)
        - top++; o topo passa a valer um a mais
        - S[top] = y; o elemento do novo topo é o y, que foi colocado

*Consultar* (PEEK) um elemento SEM desempilhá-lo:
    . x = S[top] (bisbilhotar o topo da pilha)

*Desempilhar* (POP) um elemento da pilha:
    . x = S[top--] (retirar o elemento topo da pilha)
        - Antes de retirar o elemento do topo, retorna-se ele com return x = S[top--] e logo depois decrementa-se com --

. Executaremos as funções:
. create
. destroy
. is_empty
. is_full
. push
. pop
. peek