typedef struct _node *Node; // Criação do ponteiro para a estrutura raiz
typedef struct _item Item;

// Função para criação da árvore - Cria a raiz da árvore
Node **ArvBin_create();

// Funções para desalocar a memória da Árvore
// . Liberá nós . Libera raiz
void ArvBin_destroy_node(Arv);
void ArvBin_destroy_root();


 