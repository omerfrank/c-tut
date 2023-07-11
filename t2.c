#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Hash Hash;

struct Node {
    int id;
    char name[10];
    Node *next;
};
struct Hash 
{
    int key;
    Node *arr[103];
};

void InitList(Node *head){
    head->next= NULL;
}

void InitHash(Hash *p,int keys)
{   
    p->key = keys;
    //for (int i = p->arr; i < sizeof(p->arr);i++)
    for (int i = 0; i < 103;i++)
    {
        InitList(p->arr[i]);
    }
}

void insert (Node *n, Hash *op)
{
    n->id = n->id % op->key;

    if (op->arr[n->id])
        {
        op->arr[n->id] = n;
        n->next = NULL;
        }
    else{
    }    
    Node *temp = op->arr[n->id];
    while (temp->next){
        temp = temp->next;
    }
    temp->next = n;
    temp = temp->next; 
    temp->next = NULL;  
}

void remove (Node *n, Hash *op){
    n->id = n->id % op->key;
    Node *temp = op->arr[n->id];
    while (temp->next->name != n->next->name){
        temp = temp->next;
    }
    temp->next = n->next;
}
int lookup( Hash *op, Node *n){
    Node *temp = op->arr[n->id % 103];
    while (temp){
        if (temp->name == n->name){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void tostring(Node *nd){
    printf(nd->id +"\n");
    printf(nd->name);
    printf("\n");
}
int main(int argc, char **argv)
{
    Hash arr ={""}; 
    InitHash(&arr,103);

    Node list = {""};
    

    InitList(&list);
    int i = 1;
    for (char **p = argv; *p; p++) {
        //PrintList(&list);
        Node *node = malloc(sizeof (Node));
        memset(node, 0, sizeof(Node));
        strncpy(node->name, *p, sizeof(node->name)-1);
        node->id = i;
        i++;
        insert(node,&arr);

    }
    Hash *ar= &arr; 
    
    for(Node *pnt =ar->arr;pnt <sizeof(ar->arr);pnt++ ){
        tostring(pnt);
    }

}

