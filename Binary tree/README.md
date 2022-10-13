# Árvores

- São um tipo especial de grafo (?)
- Qualquer par de vértice está conectado a apenas uma aresta (não possui ciclos)
- grafo conexo (existe apenas um caminho entre quaisquer dois vértices) e acíclico (não possui ciclos)

# DEFINIÇÃO: Conjunto não vazio de vértices (ou "nós" e "arestas" que satisfazem requisistos para serem conectadas)
Ex.: Estrutura de Diretórios do nosso computador

*Vértices ou Nós*: É cada uma das entidades representadas na árvore
. Depende da natureza do problema (usaremos a árvore pra armazenar o que? Números inteiros? Pastas? Arquivos?)

*Arestas*: É uma conexão entre dois "vértices" ou "nós"

# Aplicações
- s ão adequadas para representar estruturas hierárquicas não lineares

# Definições: Classificação dos nós

- Pai: é o antecessor imediato de um vértice
- Filho: é o antecessor imediato de um vértice
- Raiz: vértice que não possui nenhum pai
- Nós terminais ou folhas: qualquer vértice que não possui filhos
- Nós não-terminais ou internos: qualquer vértice que possui pelo menos um filho

# Caminho em uma árvore:
- Sequência de vértices de modo que existe sempre uma aresta ligando o vértice anterior com o seguinte
.OBS .: Existe exatamente um caminho ligando a raiz da árvore com cada um dos nós dela (grafo conexo)

# Sub-árvores:
- Dado um vértice, cada filho seu é a raiz de uma nova sub-árvore
- Qualquer vértice é a raiz de uma sub-árvore, formada por ele e dos nós abaixo dele

-> Grau de um vértice: número de sub-árvores do vértice

# Altura da árvore
- Ou profundidade, é o comprimento do caminho mais longo da raziz até uma das folhas

# Níveis
- Os vértices da árvore são classificados em níveis, cada vértice terá um nível/hierarquia
- O nível é o número de nós no caminho entre o vértice analisado e a raiz

# Árvores Binárias
- Tipo especial de árvore, em que cada vértice pode possuir apenas duas sub-árvores (a direita e a esquerda)
- O grau de cada vértice (número de filhos) pode ser 0 (vazio), 1 ou 2

# Árvore Estritamente binária
- O grau de cada vértice (número de filhos) pode ser APENAS 0 (vazio) ou 2! Não pode ter apenas 1 filho

# Árvore Binária Completa
- É estritamente binária e todos os seus nós-FOLHAS estão no mesmo nível (não tem desnivelamento)
- O número de nós de uma árvore binária completa é (2^h) - 1, onde h é a altura da árvore

# Árvore Binária Quase Completa
- A diferença de altura entre as sub-árvores de qualquer nó é no máximo 1
- Se a altura da árvore é D, cada nó folha está no nível "D" ou "D-1"

