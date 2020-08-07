#ifndef CREATEDOM_H
#include <stdio.h>
#include <stdlib.h>
#include "variable.h"

int num = 0;
int n = 1;

typedef struct ElementNode{
    char *data;
    struct Node *first;
    struct Node *childnode[255]; //각 노드를 하위 노드로 만들기
    struct Node *last;
    struct Node *parent;
    struct Node *nextSib;
    struct Node *prevSib;
}Node;

Node *newNode(char *);
Node *addNode(char *, Node *, int);
Node *addSib(char *, Node *);
void createDom(char*[]);
#endif