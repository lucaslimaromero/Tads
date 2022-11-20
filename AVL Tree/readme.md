# Árvores Balanceadas

> É uma árvore binária em que as alturas das sub-árvores da esquerda e da direita diferem de altura de no máximo uma unidade
> Essa diferença é chamada de fator de balanceamento do nó (fb)

> Se a sub-árvore da direita tem altura maior que a da esquerda: fb = -1
> Se a sub-árvore da esquerda tem altura maior que a da direita: fb = 1

> A eficiência da busca em uma ArvBin depende do seu balanceamento.

# Problema

> A inserção e a remoção não garantem que a árvore gerada a cada passo seja balanceada
> Sequência de inserções em ordem de "escada"

Custo de inserção, busca e remoção:
Balanceada: O(logN)
Não balanceada: O(N)

> N é o número de nós da árvore

- Solução:
Ex.: Árvore AVL, já considera no momento da inserção e remoção um possível balanceamento, para a árvore não tender para um lado ou só para o outro

# Árvore AVL - Adelson-Velskii e Landis (1962)

> Permite rebalanceamento local
> Apenas a parte afetada pela <inserção> ou <remoção> será rebalanceada
> Rotações simples ou duplas na etapa do rebalanceamento
> Ela busca manter-se como uma _Árvore Binaria Quase Completa_ (fator de balanceamento de 0 ou +-1)

# Tipos de Rotação
> Operação básica para balanceamento da árvore AVL

> Simples (a direita ou a esquerda)
-  O nó desbalanceado e seu filho estão no mesmo sentido da inclinação (os dois para a esquerda/direita)

> Duplas (a direita ou a esquerda)
- O nó desbalanceado e seu filho estão inclinados no sentido inverso ao pai
(Equivale a duas rotações simples)

# Rotação RR - Rotação simples à esquerda
- Usada quando a partir de um nó são colocados dois nós a direita dele (RR) - Right - Right

# Rotação LL - Rotação simples à direita
- Usada quando a partir de um nó são colocados dois nós a esquerda dele (LL) - Left -Left

# Rotações RL - Rotações dupla à esquerda
- Usada quando a partir de um nó são colocados um nó a direita e, nesse nó, um na esquerda em seguida (RL)
- Duas rotações simples: LL -> RR

# Rotações LR - Rotações dupla à direita
- Usada quando a partir de um nó são colocados um nó a esquerda e, nesse nó, um na direita em seguida (LR)
- Duas rotações simples: RR -> LL

# Quando usar cada rotação
Temos essa ordem A -> B -> C
> Se:
- fb(A) = +2 e fb(B) = +1: Rotação LL
- fb(A) = -2 e fb(B) = -1: Rotação RR
- fb(A) = +2 e fb(B) = -1: Rotação LR
- fb(A) = -2 e fb(B) = +1: Rotação RL
