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
