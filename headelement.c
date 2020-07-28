#include "element.h"

extern char *sptr, *eptr, *ptr;

void headParsing(char *h_element, char *h_text, char *h_tagname, char *h_temp){
    if(strcmp(h_element,"head")==0){
        ptr++;
        // setPtr(&eptr,&ptr,0);
        while(1){
            if(strncmp(ptr,">",1)==0){
                // setPtr(&eptr,&ptr,0);
                eptr=ptr;
                saveTag(h_temp,sptr,eptr,0);
                sptr=eptr;
                if(strcmp(h_temp,"/head")!=0){
                    strcpy(h_tagname,h_temp);
                    printf("headTag : %s\n",h_tagname);
                }  
                while(1){
                    if(strncmp(ptr,"<",1)==0){
                        eptr=ptr;
                        saveTag(h_text,sptr,eptr,0);
                        printf("headText : %s\n",h_text);
                        break;
                    }
                    else if(strncmp(ptr,"\n",1)==0){
                        break;
                    }
                    ptr++;   
                }                         
            }
            if(strcmp(h_temp,"/head")==0){
                strcpy(h_tagname,h_temp);
                printf("headTag : %s\n",h_tagname);
                break;
            }  
            else if(strncmp(ptr,"<",1)==0){
                sptr=ptr;
            }
            ptr++;
        }   
    }
}