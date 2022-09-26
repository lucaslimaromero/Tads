#include "linked_list.h"
#include <stdio.h>
#define N 20

int main(){

    LinkedList *L = LinkedList_create();

    LinkedList_add_last_fast(L, 10);
    LinkedList_print(L);

    LinkedList_add_last_fast(L, 2);
    LinkedList_print(L);

    LinkedList_add_last_fast(L, 4);
    LinkedList_print(L);

    LinkedList_add_last_fast(L, 5);
    LinkedList_print(L);

    LinkedList_add_last_fast(L, 7);
    LinkedList_print(L);

    LinkedList_remove_new(L, 10);
    LinkedList_print(L);

    LinkedList_remove_new(L, 4);
    LinkedList_print(L);

    LinkedList_remove_new(L,7);
    LinkedList_print(L);

    for(int i = 1; i < N; i += 2){
        LinkedList_add_last_fast(L, i);
        LinkedList_print(L);
    }

    puts("");
    printf("List Size: %lu\n", LinkedList_size(L));
    printf("First: %d\n", LinkedList_first_val(L));
    printf("Get [0]: %d\n", LinkedList_get_val(L, 0));
    printf("Get [3]: %d\n", LinkedList_get_val(L, 3));
    printf("Last: %d\n", LinkedList_last_val(L));
    puts("");

    // for(int i = 1; i < N; i += 2){
    //     LinkedList_remove_new(L, i);
    //     LinkedList_print(L);
    // }

    return 0;
}