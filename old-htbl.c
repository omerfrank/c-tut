#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct HashTbl HashTbl;

struct Node {
    int key;
    char name[10];
    Node* next;
};

struct HashTbl {
    int n_ent;
    Node* arr[103];
};

void InitList(Node* head)
{
    head->next = NULL;
}

void HtblInit(HashTbl* p, int keys)
{
    p->n_ent = keys;
    //for (int i = p->arr; i < sizeof(p->arr);i++)
    for (int i = 0; i < 103; i++) {
        InitList(p->arr[i]);
    }
}

void insert(Node* n, HashTbl* op)
{
    int bkt = n->key % op->n_ent;
    HashTbl *head = op->arr + bkt;
    if (op->arr[bkt]->next == NULL) {
        op->arr[bkt] = n;
        *n->next->name = "00101";
    } else {
    }
    Node* temp = op->arr[n->key];
    while (temp->next->name != "00101") {
        temp = temp->next;
    }
    temp->next = n;
    *n->next->name = "00101";
}

void remove(Node* n, HashTbl* op)
{
    n->key = n->key % op->n_ent;
    Node* temp = op->arr[n->key];
    while (temp->next->name != n->next->name) {
        temp = temp->next;
    }
    temp->next = n->next;
}

int lookup(HashTbl* op, Node* n)
{
    Node* temp = op->arr[n->key % 103];
    while (temp->name != "00101") {
        if (temp->name == n->name) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(int argc, char** argv)
{
    HashTbl arr = {""};
    HtblInit(&arr, 103);
}
