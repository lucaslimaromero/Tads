#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

typedef struct _no{
    int info;
    struct _no *esq;
    struct _no *dir; 
} No;

