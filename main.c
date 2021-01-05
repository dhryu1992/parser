#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>           // printf 함수, gets_s 함수를 사용하기 위해!
#include <string.h>          // strlen 함수를 사용하기 위해!
#include <malloc.h>          // malloc 함수, free 함수를 사용하기 위해!
#include <stdlib.h>
#include "variable.h"

char *arr[126] = {0,};
char *output;


int main(int argc, char ** argv[]) // argc = argument count로 main 함수에 전달된 인수의 갯수, argv = argument vector로 가변적인 개수의 문자열. 
{   
    int a = 1;
    int *order = &a;
    int t_num;
    int b = 0; 
    int c = 0;
    int i = 0;
    char buffer[MAX_LENGTH] = {0, };
    char *temp = malloc(sizeof(char));
    char *element = malloc(sizeof(char));
    char *tagname = malloc(sizeof(char));
    char *context = malloc(sizeof(char)*MAX_LENGTH*2);
    char *text = malloc(sizeof(char));
    char *attname = malloc(sizeof(char));
    char *value = malloc(sizeof(char));
    for(i = 0; i < 126; i++) {
        arr[i] = malloc(sizeof(char));
    }
 
    *context = 0;   *text = 0;
    *element = 0;   *tagname = 0;
    *attname = 0;   *value = 0;
    *temp = 0;
    
    if(argc > 2)
        printf("입력오류 (main.o 파일명)\n");
    else {
        FILE *fp = fopen(argv[1],"r");
        if(fp == NULL) {
            fclose(fp);
            return 1;
        }

        while((feof(fp)) == 0)  //파일 끝까지 1바이트씩 buffer로 읽어온 후 context로 이동
        {
            fread(&buffer, sizeof(char), 1, fp);
            if(feof(fp) == 0)
                strcat(context, buffer);
        }
        fclose(fp);
    }
    sptr = context;
    ptr = &sptr[1];
    eptr = &ptr[0];
    printf("--Parsing-- \n");
    while(strncmp(ptr, "\0", 1) != 0) {
        ptr = &ptr[1]; 
        if(strncmp(ptr, ">", 1) == 0) {//<태그>태그 확인
            
            docParsing(element, attname, value);
            headParsing(element, text, tagname, temp);
            bodyParsing(element, text, tagname, value, temp, attname);
        }
        else if(strncmp(ptr, "<", 1) == 0) {// <검출 위의 if문과 합쳐져서 태그 획득
            sptr = &ptr[0];
        }       
    }
    printf("--TreeNode-- \n");
    while(1) {
        if(strcmp(arr[b], "\0") == 0) {
            b = *order;
            // printf("break;\n");
            // printf("%d %d\n",b, *order);
            break;
        }
        
        createDom(arr, order, &t_num);
        b = *order;
        // c = *t_num;
        // printf("%d\n",b);
        // printf("%s\n",output);
    }
    printf("--Dom Tree-- \n");
    showTree(t_num);
    freeNode();
    
    // while(strcmp(arr[i],"\0")!=0){
    //     printf("arr[%d] %s\n",i, arr[i]);
    //     free(arr[i]);
    //     i++;
    // }
    for(i = 0; i<126; i++) {
        free(arr[i]);
    }
    free(context);  free(element);
    free(text);     free(tagname);
    free(attname);  free(temp);
    free(value);  
    return 0;    
}
