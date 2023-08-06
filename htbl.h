#ifndef _HTBL_H_
#define _HTBL_H_
typedef struct Node Node;
typedef struct HashTbl HashTbl;

#define NAME_SZ 10

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Node
{
    unsigned key; // unique key
    char name[NAME_SZ];
    Node *next;
};

struct HashTbl
{
    int n_ent; // number of bukeats in hash tbl;
    Node **heads;
};

void HtblInit(HashTbl *tbl, int keys);
void HtblInsert(HashTbl *tbl, Node *n);
int HtblRemove(HashTbl *tbl, Node *n);
Node *HtblLookup(HashTbl *op, char *name);
void PrintBucket(int bkt, Node *nd);
unsigned hash(char *str);

#endif // _HTBL_H_
