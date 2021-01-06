#include "domVariable.h"
#include "variable.h"
void createDom(char* tag[],int *order,int *t_num) {

// for(int y = 0; y <30; y++){
    if(stp==NULL){
        stp = newNode(tag[n]);
        node[num] = stp;
        printf("%d : %s\n",num, node[num]->data);
        num++; count++;
        // printf("%d : %s\n",num, node[num]->data);
    }
    else {
        if(strncmp(tag[n],"/",1)==0) {// /만나면 상위 노드로
                for(int i = 0; i < count; i++) {
                    stp = stp->parent;
                    if(strcmp(stp->data, "body") == 0)
                    {
                        count--;
                    }
                }
            c_Num++;
            count = 0;
        }else if(strcmp(stp->data, "html") == 0) {
            stp = addNode(tag[n],stp,h_Num);
            node[num] = stp;
            printf("%d : %s\n", num, node[num]->data); 
            num++; 
            h_Num++; 
            count;
            c_Num = 0;
        }else if(strcmp(stp->data,"img") == 0 ) {//이미지일경우
            sstp=stp;
            while(1) {
                sstp = addSib(tag[n], sstp);//att노드 생성
                node[num] = sstp;
                printf("%d : %s\n", num, node[num] -> data);
                num++; 
                n++;
                node[num]=addNode(tag[n], sstp, 0);//value 노드 생성
                printf("%d : %s\n", num, node[num]->data);
                num++; 
                n++;
                if(strcmp(tag[n], "/img") == 0) {
                    c_Num++;
                    count = 0;
                    stp = stp->parent;
                    break;
                }
            }
        }else{
            if(count == 1) {
                stp = addNode(tag[n], stp, 0);//태그 내부 데이터
            }else{
                stp = addNode(tag[n], stp, c_Num);//childnode 생성
            }
                
            node[num] = stp;
            printf("%d : %s\n", num, node[num]->data);
            num++; 
            count++;
        }
    }
    n++;//실행시마다 다음 tag[]배열로 이동
    *order = n;//main에서 arr[](tag[])값 증가
    *t_num = num;//main에서 트리 생성시 필요한 배열값
    return 0;
}

void showTree(int t_Count) {
    int nodeNum = 0;
    int childNum = 0;
    int levelCount = 0;
    // stp = node[nodeNum];
    // for(nodeNum = 0; nodeNum<t_Count; nodeNum++){
    //     printf("Tree : %s\n",stp->data);
    //     if(stp->nextSib!=NULL){
    //         // stp = 
    //     }else{
    //         if(stp->childnode[childNum]!=NULL){
    //             stp = stp->childnode[0];
                
    //         }
    //         else if(stp->childnode[childNum]==NULL){
                
    //             stp = stp->parent;
    //             printf("%d\n",childNum);
    //             childNum++;
    //         }

    //     }
    // }
    stp = node[0];//html
    printf("%s\n", stp->data);
    stp = stp -> childnode[0];//head
    printf(" ├%s\n", stp->data);
    stp = stp -> childnode[0];//title
    printf(" │  └%s\n", stp->data);
    stp = stp -> childnode[0];//documnet
    printf(" │      └%s\n", stp->data);
    for(int i = 0; i<3; i++){
        stp = stp -> parent;
    }
stp = stp -> childnode[1];//body
printf(" └%s\n", stp->data);
sstp = stp -> childnode[0];

if(sstp -> nextSib != NULL){
    stp = stp -> childnode[0];//image
    printf("    ├─%s\n",stp -> data);
    printf("    │  │\n");

    while(stp -> nextSib != NULL){
        stp = stp -> nextSib;//src
        printf("    │ %s\n", stp -> data);
        stp = stp -> childnode[0];//src child
        printf("    │  ├─%s\n", stp -> data);
        stp = stp -> parent;
    }
    stp = sstp -> parent;

    stp = stp -> childnode[1];
    printf("    ├─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("    │  └─%s\n", stp -> data);
        for(int i = 0; i<2; i++){
            stp = stp -> parent;
        }
    stp = stp -> childnode[2];
    printf("    ├─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("    │  └─%s\n", stp -> data);
        for(int i = 0; i<2; i++) {
            stp = stp -> parent;
        }
    stp = stp -> childnode[3];
    printf("    └─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("       └─%s\n", stp -> data);  
}else{
    stp = stp -> childnode[0];
    printf("    ├─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("    │  └─%s\n", stp -> data);
        for(int i = 0; i<2; i++) {
            stp = stp -> parent;
        }
    stp = stp -> childnode[1];
    printf("    ├─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("    │  └─%s\n", stp -> data);
        for(int i = 0; i<2; i++) {
            stp = stp -> parent;
        }
    stp = stp -> childnode[2];//image
    printf("    ├─%s\n", stp -> data);
    printf("    │  │\n");
    while(stp -> nextSib != NULL) {
        stp = stp -> nextSib;//src
        printf("    │ %s\n", stp -> data);
        stp = stp -> childnode[0];//src child
        printf("    │  ├─%s\n", stp -> data);
        stp = stp -> parent;
    }
    stp = sstp -> parent;

    stp = stp -> childnode[3];
    printf("    └─ %s\n", stp -> data);
    stp = stp -> childnode[0];
    printf("       └─%s\n", stp -> data);
    }
}

void freeNode(){
    for(int i = 0; i < num; i++){
        free(node[i]);
    }
}

Node *newNode(char *text)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current -> data = text;
    current -> first = current -> last = current->parent = NULL;
    return current;
}


Node *addNode(char *text, Node *upper, int cNum)
{
    Node *adptr = (Node *)malloc(sizeof(Node));
    adptr -> data = text;
    adptr -> parent = upper;
    adptr -> first = adptr -> last = adptr -> nextSib = NULL;
    if(upper -> first == NULL) {
        upper -> first = adptr;
        upper -> childnode[cNum] = adptr;
    }
    else if(upper -> first != NULL) {
        upper -> last = adptr;
        upper -> childnode[cNum] = adptr;
    }
    return adptr;
}
//형제노드 x, 형제 노드로 이어줌
//있으면, 하위노드로, 
Node *addSib(char *text, Node *prev)
{
    Node *sibptr = (Node *)malloc(sizeof(Node));
    sibptr -> data = text;
    sibptr -> first = sibptr -> last = sibptr -> prevSib = sibptr -> nextSib = NULL;
    sibptr -> prevSib = prev;
    prev -> nextSib = sibptr;
    return sibptr;
}
