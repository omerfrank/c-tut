#include <stdlib.h>
#include <string.h>
#include "htbl.h"
#include <stdio.h>



unsigned
hash(char *str)
{
    unsigned hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

Node* nodebuilder(char* str ){
    Node *n = malloc(sizeof(Node));
    n->key = hash(str);
    strncpy(n->name,str,sizeof(n->name));
    return n;

}

int main(int argc, char **argv)
{
    char str[256];
    HashTbl *tbl = {""};

    FILE *file = fopen(argv[1], "r");
    while (!fgets(str, 256, file))
    {
        if (HtblLookup(tbl , hash(str))){
            continue;
        }
        HtblInsert(tbl,nodebuilder(str));
        printf(str);
    }
}