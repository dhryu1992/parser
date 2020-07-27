#include "function.h"

void saveTag(char *name, char *start, char *end, int num){
    
    switch(num){
        case 0 :
            memcpy(name, ++start,end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 1 :
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 2 :
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            break;
    }
}

void fp_saveTag(char *name, char *start, char *end, char **current, int num){
    char **dest = &end;
    switch(num){
        case 0 :
            *dest=*current;
            memcpy(name, ++start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 1 :
            *dest=*current;
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 2 :
            *dest=*current;
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            break;
    }
}

void rp_saveTag(char *name, char *start, char *end, int num){
    switch(num){
        case 0 :
            memcpy(name, ++start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            start=end;
            break;
        case 1 :
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            start=end;
            break;
        case 2 :
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            start=end;
            break;
    }
}

void setPtr(char **start, char **end){
    *start=*end;
}

void copyTag(char *name, char *buf)
{
    strcpy(name,buf);
    printf("bodyele:%s\n",name);
}
