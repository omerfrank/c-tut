#include <stdlib.h>
#include <string.h>
#include "htbl.h"

int main(int argc, char** argv)
{
    HashTbl arr = {};
    HtblInit(&arr, 3);

    int i = 1;
    
    for (char** p = argv; *p; p++) {
        //PrintList(&list);
        Node* node = calloc(1, sizeof(Node));
        strncpy(node->name, *p, sizeof(node->name) - 1);
        node->key = i;
        i++;
        HtblInsert(&arr, node);
    }

    HashTbl* ar = &arr;

    for (int n  = 0 ; n < ar->n_ent; n++) {
        PrintBucket(n, ar->heads[n]);
    }
    
    return 0;
}
