#include "element.h"

extern char *sptr, *eptr, *ptr;

void docParsing(char *d_element, char *d_attname, char *d_value){
    eptr=ptr;
    if(strncmp(sptr+1,"!",1)==0){
                    sptr++;
                    saveTag(d_element,sptr,eptr,0);
                    printf("html--v : %s\n",d_element);
                }
                else{
                    saveTag(d_element,sptr,eptr,0);
                    printf("docEle : %s\n",d_element);
                }
                ptr++;
}