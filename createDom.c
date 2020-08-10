#include "domVariable.h"
#include "variable.h"
char createDom(char* tag[],int *order){

n = *order;
// for(int y = 0; y <30; y++){
    if(stp==NULL){
        stp = newNode(tag[n]);
        node[num] = stp;
        num++; count++;
        // printf("%d : %s\n",num, node[num]->data);
    }
    else{
        if(strncmp(tag[n],"/",1)==0){// /만나면 상위 노드로
                for(int i = 0; i < count; i++)
                {
                    stp = stp->parent;
                    if(strcmp(stp->data,"body")==0)
                    {
                        count--;
                    }
                }
            c_Num++;
            count = 0;
        }else if(strcmp(stp->data,"html")==0){
            stp = addNode(tag[n],stp,h_Num);
            node[num] = stp;
            printf("%d : %s\n",num, node[num]->data);
            num++; h_Num++; count;
            c_Num = 0;
        }else if(strcmp(stp->data,"img")==0){
            sstp=stp;
            while(1){
                sstp = addSib(tag[n],sstp);
                node[num] = sstp;
                printf("%d : %s\n",num,node[num]->data);
                num++;n++;
                node[num]=addNode(tag[n],sstp,0);
                printf("%d : %s\n",num,node[num]->data);
                num++; n++;
                if(strcmp(tag[n],"/img")==0){
                    c_Num++;
                    count = 0;
                    stp = stp->parent;
                    break;
                }
            }
        }else{
            if(count == 1){
                stp = addNode(tag[n],stp,0);
            }else{
                stp = addNode(tag[n],stp,c_Num);
            }
                
            node[num] = stp;
            printf("%d : %s\n",num, node[num]->data);
            num++; count++;
        }
    }
    *order = n+1;




// stp = node[0]->childnode[1];
// printf("%s\n",stp->data);


}

void showTree(){
    int nodeNum = 1;
    int childNum = 0;
    stp = node[nodeNum];
    for(nodeNum = 1; nodeNum<30; nodeNum++){
        if(strcmp(stp->data,"html")!=0){
            if(stp->childnode[childnode]!=NULL){
                stp = node[nodeNum]->childnode[0];
                printf("%s\n",stp->data);
                childnode++;
            }
            else if(stp->childnode[childnode]==NULL){
                stp = stp->parent;
                childnode = 0;
            }
        }else if(strcmp(stp->data,"html")==0){
            stp = node[nodeNum];
            printf("%s\n",stp->data);
        }
    }
stp = node[0];//html
printf("%s\n",stp->data);
stp = stp->childnode[0];//head
printf(" └%s\n",stp->data);
stp = stp->childnode[0];//title
printf(" │  └%s\n",stp->data);
stp = stp->childnode[0];//documnet
printf(" │      └%s\n",stp->data);
    for(int i = 0; i<3; i++){
        stp = stp->parent;
    }
stp = stp->childnode[1];//body
printf(" └%s\n",stp->data);

stp = stp->childnode[0];//image
printf("    ├─%s\n",stp->data);
printf("    │  │\n");

stp = stp->nextSib;//src
printf("    │ %s\n",stp->data);
stp = stp->childnode[0];//src child
printf("    │  ├─%s\n",stp->data);
stp = stp->parent;

stp = stp->nextSib;//alt
printf("    │ %s\n",stp->data);
stp = stp->childnode[0];
printf("    │  ├─%s\n",stp->data);
stp = stp->parent;

stp = stp->nextSib;//width
printf("    │ %s\n",stp->data);
stp = stp->childnode[0];//width child
printf("    │  ├─%s\n",stp->data);
stp = stp->parent;

stp = stp->nextSib;//height
printf("    │ %s\n",stp->data);
stp = stp->childnode[0];//height child
printf("    │  ├─%s\n",stp->data);
stp = stp->parent;

stp = node[4]->childnode[1];
printf("    ├─ %s\n",stp->data);
stp = stp->childnode[0];
printf("    │   └%s\n",stp->data);
stp = node[4]->childnode[2];
printf("    ├─ %s\n",stp->data);
stp = stp->childnode[0];
printf("    │  └─%s\n",stp->data);
stp = node[4]->childnode[3];
printf("    ├─ %s\n",stp->data);
stp = stp->childnode[0];
printf("    │  └─%s\n",stp->data);
stp = node[4]->childnode[4];
printf("    └─ %s\n",stp->data);
stp = stp->childnode[0];
printf("       └─%s\n",stp->data);
}

void freeNode(){
    for(int i = 0; i < num; i++){
        free(node[i]);
    }
}

Node *newNode(char *text)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = text;
    current->first = current->last = current->parent = NULL;
    return current;
}


Node *addNode(char *text, Node *upper, int cNum)
{
    Node *adptr = (Node *)malloc(sizeof(Node));
    adptr->data = text;
    adptr->parent = upper;
    adptr->first = adptr->last = NULL;
    if(upper->first == NULL) {
        upper->first = adptr;
        upper->childnode[cNum] = adptr;
    }
    else if(upper->first != NULL) {
        upper->last = adptr;
        upper->childnode[cNum] = adptr;
    }
    return adptr;
}
//형제노드 x, 형제 노드로 이어줌
//있으면, 하위노드로, 
Node *addSib(char *text, Node *upper)
{
    Node *sibptr = (Node *)malloc(sizeof(Node));
    sibptr->data = text;
    sibptr->first = sibptr->last = sibptr->prevSib = sibptr->nextSib = NULL;
    sibptr->prevSib = upper;
    upper->nextSib = sibptr;
    return sibptr;
}