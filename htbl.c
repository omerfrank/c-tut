#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

void HtblInit(HashTbl* tbl, int keys)
{
    tbl->n_ent = keys;
    tbl->heads = calloc(keys, sizeof (Node*));
}

void HtblInsert(HashTbl* tbl, Node* n)
{
    int bktid = n->key % tbl->n_ent;

    n->next = tbl->heads[bktid];
    tbl->heads[bktid] = n;
}

unsigned 
hash(char *str)
{
    unsigned hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}


int HtblRemove(HashTbl* tbl, Node* n)
{
    int bktid = n->key % tbl->n_ent;
    Node* p = tbl->heads[bktid];

    if (p->key == n->key) {
        tbl->heads[bktid] = p->next;
        return 1;
    }
    while (p) {
        if (p->next && p->next->key == n->key) {
            p->next = p->next->next;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int HtblRemove2(HashTbl* op, Node* n)
{
    int bktid = n->key % op->n_ent;

    for (Node** p = &op->heads[bktid]; *p; p = &((*p)->next)) {
        if ((*p)->key == n->key) {
            *p = (*p)->next;
            return 1;
        }
    }
    return 0;
}

Node *HtblLookup(HashTbl* op, char *name)
{
    
    unsigned key = hash(name);
    Node* tmp = op->heads[key % op->n_ent];
    // printf("node:  \n");
    while (tmp) {
        if (tmp->key == key && strncmp(name,tmp->name,NAME_SZ ) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void PrintBucket(int bkt, Node* nd)
{
    while (nd) {
        printf("Bkt %d: Node key %d name '%s' \n",  bkt, nd->key, nd->name);
        nd = nd->next;
    }
}

