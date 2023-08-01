#ifndef _HTBL_H_
#define _HTBL_H_
typedef struct Node Node;
typedef struct HashTbl HashTbl;

#define NAME_SZ 10

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Node {
    int key;            // unique key
    char name[NAME_SZ];
    Node* next;
};

struct HashTbl {
    int n_ent;
    Node **heads;
};

void HtblInit(HashTbl* tbl, int keys);
void HtblInsert(HashTbl* tbl, Node* n);
int HtblRemove(HashTbl* tbl, Node* n);
Node *HtblLookup(HashTbl* op, int key);
void PrintBucket(int bkt, Node* nd);

#endif  // _HTBL_H_

