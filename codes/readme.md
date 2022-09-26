## ENTENDENDO TADS

Na nossa analogia, temos as seguintes coisas:
*1*. Um drone (Produto Fechado) - sem acesso a implementação
*2*. Um controle - .c + .h = (.o)
*3*. Manual (Funcionalidades/Especificações) 

- Os TADs dividem as especificações (o que faz) da implementação (como faz) do programa.
- Quando definimos um TAD estamos preocupados com o que ele faz e não como.

*Especificação* - Sintaxe (assinatura/'declaração' das funções) e semântica (o que cada função faz)
*Implementação* - Representação (estruturas de dados) e Algoritmos

. seu_tad.h: *especificação da TAD* (h -> header, arquivo de cabeçalho)
. seu_tad.c: *implementação da TAD* (source code, que vc compila e gera o .o, que seria o produto final)

. seu_tad.o: *executável* (seria o controle remoto do drone)

#include "seu_tad.h"

## Vantagens de TAD

*1*. Reutilização (abstraindo os detalhes da implementação, que seria o .c) em outros programas das mesmas funções já criadas
*2*. Facilidade de manutenção: mudanças na implementação (.c) não afetam o código fonte '(.o)' dos programas que o utilizam (ocultamento de informação)
*3*. Corretude: códigos testados várias vezes em diferentes contextos

# OBS.: 

Na hora de passar arquivos para outras pessoas do nosso programa, ao subdividir ele em pastas - *Pasta* (arquivo guardado):

- *apps* (arquivos executáveis com main, sendo os nossos programas)
- *bin* (arquivos binários dos programas compilados)

- *include* (arquivos .h, cabeçalho dos TADs)
- *src* (source, com os arquivos fontes .c de implementação dos TADs)
- *obj* (objetos executáveis, nossos TADs compilado)
