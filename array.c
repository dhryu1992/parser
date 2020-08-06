#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int aa;
char* copyChar1(char* src);
char *abc;
char *arr[255];
int n = 0;
int main(){
    
    char *temp[3] ={0,};
    
    
    abc = "bbc";
    for(int i =0; i<5;i++){
    copyChar(abc);
    printf(" %s\n",arr[i]);
    }
}

char* copyChar1(char* src)
{
    char *dst = NULL;
    dst = (char*)malloc(sizeof(char)*strlen(src)+1);
    memcpy(dst,src,strlen(src));
    arr[n] = dst;
    n++;
}