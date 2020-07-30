#include <stdio.h>
#include <stdlib.h>

typedef struct ElementNode{
    char *data;
    struct Node *first;
    // struct Node *childnode;
    // struct Node *last;
    // struct Node *parent;
}Node;

typedef struct NodeList{
    int num;
}List;

void main(){
    Node *ptr;
    Node *HTML = malloc(sizeof(Node));
    HTML->data = "head";
    printf("%s\n",HTML->data);
    if(strcmp(HTML->data,"head")==0){
        
        HTML->first = malloc(sizeof(Node));
        Node *head = HTML->first;
        ptr = HTML;
        HTML->first->data = "adbd";
        printf("%s\n",ptr->data);
        
    }
}
// Node *N;
// N->childnode->num;

// tagname = html;

// void 1(){
//     Node html;
//     html->data = element;
//     html->first = NULL;
//     html->last = NULL;
// }
// prevtagname = tagname;
// tagname = head
// void 2(char tagnaem, char prevtagnae){
//     int a;
//     Node tagname = malloc;
//     tagnaem[a];
//     tagname[a]->parent = prevtagname;
//     prevtagname->childnode[a] = tagname[a];
//     if(prevtagname->first==NULL)
//         prevtagname[a]->first = tagname[a];
//     else if(revtatname->first != NULL){
//         prevtagname[a]->last = tagname[a];
//     }
//     a++;
// }