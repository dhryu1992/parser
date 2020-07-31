#include <stdio.h>
#include <stdlib.h>

int num = 0;
int i = 0;
int istag = 0;

typedef struct ElementNode{
    char *data;
    struct Node *first;
    // struct Node *childnode; //각 노드를 하위 노드로 만들기
    struct Node *last;
    struct Node *parent;
}Node;

Node *NewNode(char *text)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = text;
    current->first = current->last = current->parent = NULL;
    return current;
}

Node *addNode(char *text, Node *upper)
{
    Node *aptr = (Node *)malloc(sizeof(Node));
    aptr->data = text;
    aptr->parent = upper;
    aptr->first = aptr->last = NULL;
    if(upper->first == NULL) {
        upper->first = aptr;
    }
    else{
        upper->last = aptr;
    }
    return aptr;
}

void main(){
    Node *stp = NULL;
    Node *node[100];
    char *tagname;
    
    char *tag[100] = {"html","head","title","document","/title","/head","body","p","text","/p","p","text2","/p","/body","/html","\0"};
    // tagname = "html";
    // if(strcmp(tag[11],"\0")==0){
    //     printf("ok\n");
    // }

    while(1){//마지막에 /html태그 출력 안됨
        if(strcmp(tag[i],"\0")==0){
            break;
        }
        else if(stp==NULL){
            stp = NewNode(tag[i]);
            node[num] = stp;
            // printf("%d\n",num);
            // printf("1\n");
            printf("%s\n",node[num]->data);
            num++;
        }
        else{
            if(strncmp(tag[i],"/",1)==0){// /만나면 상위 노드로
                stp = stp->parent;
                // printf("%d\n",num);
                // printf("2\n");
                // printf("%s\n",stp->data);
            }else{
                if(strcmp(tag[i],"document")==0){
                    stp = addNode(tag[i],stp);
                    node[num] = stp;
                    // printf("%d\n",num);
                    // printf("3\n");
                    printf("%s\n",node[num]->data);
                    stp = node[num]->parent;
                    num++; 
                }else{
                    // printf("%s\n",tag[i]);
                    stp = addNode(tag[i],stp);
                    node[num] = stp;
                    // printf("%d\n",num);
                    // printf("3\n");
                    printf("%s\n",node[num]->data);
                    num++;
                }
            }
        }
        i++;
    }
    printf("okokok\n");
    stp = node[2]->parent;
    printf("%s\n",stp->data);
    free(stp);
    // if(stp==NULL){
    //     stp = NewNode(tagname);
    //     node[num] = stp;
    //     printf("%d\n",num);//0
    //     num++;
    // }
    // else{
    //     if(strncmp(tagname,"/",1)==0){
    //         stp = node[num-1]->parent;
    //     }else{
    //         stp = addNode(tagname,stp);
    //         node[num] = stp;
    //         num++;
    //     }
    // }

    // printf("%d\n",num);//1
    // tagname = "head";
    // if(stp==NULL){
    //     stp = NewNode(tagname);
    //     node[num] = stp;
    //     printf("%d\n",num);//0
    //     num++;
    // }
    // else{
    //     if(strncmp(tagname,"/",1)==0){
    //         stp = node[num-1]->parent;
    //     }else{
    //         stp = addNode(tagname,stp);
    //         node[num] = stp;
    //         num++;
    //     }
    // }

    // printf("%d\n",num);//2
    // tagname = "title";
    // if(stp==NULL){
    //     stp = NewNode(tagname);
    //     node[num] = stp;
    //     printf("%d\n",num);//0
    //     num++;
    // }
    // else{
    //     if(strncmp(tagname,"/",1)==0){
    //         stp = node[num-1]->parent;
    //     }else{
    //         stp = addNode(tagname,stp);
    //         node[num] = stp;
    //         num++;
    //     }
    // }

    // printf("%d\n",num);//3
    // tagname = "/title";
    
    // if(stp==NULL){
    //     stp = NewNode(tagname);
    //     node[num] = stp;
    //     printf("%d\n",num);//0
    //     num++;
    // }
    // else{
    //     if(strncmp(tagname,"/",1)==0){
    //         stp = node[num-1]->parent;
    //     }else{
    //         stp = addNode(tagname,stp);
    //         node[num] = stp;
    //         num++;
    //     }
    // }
    // node[num] = addNode("body",stp);

    // printf("%s\n",node[0]->data);
    // printf("%s\n",node[1]->data);
    // printf("%s\n",node[2]->data);
    // printf("%s\n",stp->data);
    // Node *ptr;
    // Node *HTML = malloc(sizeof(Node));
    // HTML->data = "head";
    // printf("%s\n",HTML->data);
    // if(strcmp(HTML->data,"head")==0){
        
    //     HTML->first = malloc(sizeof(Node));
    //     Node *head = HTML->first;
    //     ptr = HTML;
    //     HTML->first->data = "adbd";
    //     printf("%s\n",ptr->data);
        
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