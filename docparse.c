#include "element.h"

extern char *sptr, *eptr, *ptr;

void docParsing(char *d_element, char *d_attname, char *d_value){
    if(strncmp(ptr,"!",1)==0){
        sptr=ptr;
        while(1){
            ptr++;
            if(strncmp(ptr," ",1)==0){
                eptr=ptr;
                saveTag(d_element,sptr,ptr,0);
                sptr=ptr;
            }
            else if(strncmp(ptr,">",1)==0){
                eptr=ptr;
                saveTag()
            }
        }       
    }
}