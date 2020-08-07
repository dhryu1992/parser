#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>           // printf 함수, gets_s 함수를 사용하기 위해!
#include <string.h>          // strlen 함수를 사용하기 위해!
#include <malloc.h>          // malloc 함수, free 함수를 사용하기 위해!
#include <stdlib.h>
#include "variable.h"

char *arr[126] = {0,};

int main()
{    
    // elementNode ele;
//     ele = malloc(element(sizeof()))
    // for (int i = 0; i < sizeof(childNodes) / sizeof(struct eNode *); i++)    // 요소 개수만큼 반복
    // {
    //     childNodes[i] = malloc(sizeof(struct eNode));
    // }

    FILE *fp = fopen("test.html","r");
    if (fp == NULL) {
        fclose(fp);
        return 1;
    }
    char buffer[MAX_LENGTH] = {0, };
    char *temp = malloc(sizeof(char)*MAX_LENGTH);
    char *element = malloc(sizeof(char)*MAX_LENGTH);
    char *tagname = malloc(sizeof(char)*MAX_LENGTH);
    char *context = malloc(sizeof(char)*MAX_LENGTH);
    char *text = malloc(sizeof(char)*MAX_LENGTH);
    char *attname = malloc(sizeof(char)*MAX_LENGTH);
    char *value = malloc(sizeof(char)*MAX_LENGTH);
    for(int i = 0; i<126; i++){
        arr[i] = malloc(sizeof(char));
    }
 
    *context = 0;   *text = 0;
    *element = 0;   *tagname = 0;
    *attname = 0;   *value = 0;
    *temp = 0;
    while((feof(fp)) == 0)  //파일 끝까지 1바이트씩 buffer로 읽어온 후 context로 이동
    {
        fread(&buffer,sizeof(char),1,fp);
        if(feof(fp)==0)
            strcat(context,buffer);
    }
    fclose(fp);
    sptr=context;
    ptr=&sptr[1];
    eptr = &ptr[0];
    int i = 0;
    while(strncmp(ptr,"\0",1)!=0){
        ptr=&ptr[1]; 
        // if()
        if(strncmp(ptr,">",1)==0){//<태그>태그 확인
            docParsing(element, attname, value);
        //    printf("%d %s\n",arrnum,arr[0]);
            headParsing(element, text, tagname, temp);
        //    printf("%d %s\n",arrnum,arr[1]);
        //    printf("%d %s\n",arrnum,arr[2]);
            bodyParsing(element, text, tagname, value, temp, attname);
        }
        else if(strncmp(ptr,"<",1)==0){// <검출 위의 if문과 합쳐져서 태그 획득
            sptr=&ptr[0];
        }       
    }
    createDom(arr);
    // while(strcmp(arr[i],"\0")!=0){
    //     printf("arr[%d] %s\n",i, arr[i]);
    //     free(arr[i]);
    //     i++;
    // }
    
    free(context);  free(element);
    free(text);     free(tagname);
    free(attname);  free(temp);
    free(value);  
    return 0;    
}