#ifndef DOMVARIABLE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ElementNode{
    char *data;
    struct Node *first;
    struct Node *childnode[255]; //각 노드를 하위 노드로 만들기
    struct Node *last;
    struct Node *parent;
    struct Node *nextSib;
    struct Node *prevSib;
}Node;

Node *node[100];
Node *stp = NULL;
Node *sstp = NULL;
Node *test = NULL;   
char *tagname;
int c_Num = 0;
int h_Num = 0;
int count = 0;
int t_Num = 0;
int num = 0;
int n = 0;

Node *newNode(char *);
Node *addNode(char *, Node *, int);
Node *addSib(char *, Node *);

char createDom(char*[],int*);
void showTree();
void freeNode();
#endif