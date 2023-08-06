#include <stdlib.h>
#include <string.h>
#include "htbl.h"
#include <stdio.h>
#include <errno.h>




Node* nodebuilder(char* str ){
    Node *n = malloc(sizeof(Node));
    n->key = hash(str);
    strncpy(n->name,str,sizeof(n->name));
    return n;

}

int main(int argc, char **argv)
{
    char str[256];
    HashTbl *tbl = calloc(1,sizeof(HashTbl));
    HtblInit(tbl,5);
    FILE *file = fopen(argv[1], "r");
    if (!file){
        printf("error opening file '%s': %m\n", argv[1]);
        exit(1);
    }

    while (fgets(str, 256, file))
    {
        //printf("string: %s \n", str );
        if (HtblLookup(tbl , str)){
            continue;
        }
       // printf("lookup suscces \n");
        HtblInsert(tbl,nodebuilder(str));
        puts(str);
    }
}