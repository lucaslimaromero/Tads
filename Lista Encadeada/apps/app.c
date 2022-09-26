#include "linked_list.h"

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

    LinkedList_remove(L, 10);
    LinkedList_print(L);

    return 0;
}