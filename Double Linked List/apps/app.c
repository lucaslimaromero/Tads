#include "list.h"
#include <stdio.h>


int main(){
    
    List *L = List_create(); // 10 - 2 - 4 - 7

    List_print(L);
    List_inverted_print(L);

    List_remove(L, 99);
    List_print(L);
    List_inverted_print(L);

    List_add_last(L, 10);
    List_add_last(L, 2);
    List_add_last(L, 4);
    List_add_last(L, 7);

    List_print(L);
    List_inverted_print(L);

    List_remove(L, 10);
    List_print(L);
    List_inverted_print(L);

    List_remove(L, 2);
    List_print(L);
    List_inverted_print(L);

    List_remove(L, 4);
    List_print(L);
    List_inverted_print(L);
    
    List_remove(L, 7);
    List_print(L);
    List_inverted_print(L);

    List_destroy(&L);

    return 0;
}