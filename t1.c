#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Node Node;

struct Node {
    char name[10];
    Node *next;
    Node *prev;    
};


struct Node {
    char name[10];
    Node *next;
};


void InitList(Node *head)
{   
    strcpy(head->name, "dummy");
    head->prev = head;
    head->next = head;
}

void AppendNode(Node *head, Node *newnode)
{
    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
}

void PushNode(Node *head, Node *newnode)
{
    head->next->prev = newnode;
    newnode->next = head->next;
    head->next = newnode;
    newnode->prev = head;
}

void RemoveNode(Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void RemoveSNode(Node *list, Node *node)
{
    while (list && list->next != node) {
        list = list->next;
    }
    if (list) {
        list->next = node->next;
    }
}

void PrintList(Node *head)
{
    for (Node *n = head; ; n = n->next) {
        printf("Node %p: name %s next %p prev %p\n", n, n->name, n->next, n->prev);
        if (n->next == head)
            break;
    }
}

int main(int argc, char **argv)
{
    //usuless parts
    /*printf("Hello world\n");
    printf("Argc is %d\n", argc);
    for (char **p = argv; *p; p++) {
        printf("arg: %ld: %s\n", p-argv, *p);
    }*/
    Node list = {""};
    Node *slist = NULL;

    

    InitList(&list);
    for (char **p = argv; *p; p++) {
        //PrintList(&list);
        Node *node = malloc(sizeof (Node));
        memset(node, 0, sizeof(Node));
        strncpy(node->name, *p, sizeof(node->name)-1);
        PushNode(&list, node);
    }

    for (char **p = argv; *p; p++) {
        //PrintList(&list);
        Node *node = malloc(sizeof (Node));
        memset(node, 0, sizeof(Node));
        strncpy(node->name, *p, sizeof(node->name)-1);
        node->next = slist;
        slist = node;
    }

    for (Node *n = list.next; n != &list; n = n->next) {
        printf("Node %p: %s\n", n, n->name);
    }
    return 0;
}
