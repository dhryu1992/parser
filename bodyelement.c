#include "element.h"

extern char *sptr, *eptr, *ptr;

void bodyparse(char *b_element, char *b_text, char *b_tagname, 
                char *b_value, char *b_temp, char *b_attname){
    int isspace=0;
    if(strcmp(b_element,"body")==0){//바디 태그 내용 추출
        int i = 0;
        ptr=&ptr[1];//<body>에서 포인터를 한칸만 이동시 \n, 공백으로 출력
        while(1){
            ptr=&ptr[1];
            if(strncmp(ptr," ",1)!=0 && isspace==0){
                sptr=ptr;
                isspace = 1;
                if(strncmp(ptr,"<",1)!=0){//텍스트+태그 출력, 12345<br>
                    while(strncmp(ptr,"\n",1)!=0){//전부 출력후 개행문자 확인시까지 반복
                        ptr=&ptr[1];
                        if(strncmp(ptr,"<",1)==0){//텍스트 출력
                            eptr=ptr;
                            saveTag(b_text,sptr,eptr,1);
                            printf("bodyText : %s\n",b_text);
                        }
                        else if(strncmp(ptr,">",1)==0){//태그 출력
                            saveTag(b_tagname,eptr,ptr,2);
                            printf("bodyTag : %s\n",b_tagname);
                            break;
                        }
                    }
                }
                else if(strncmp(ptr,"<",1)==0){//태그 내부 출력
                    eptr=&ptr[0];
                    while(1){
                        ptr=&ptr[1];
                        if(strncmp(ptr," ",1)==0){
                            if(strncmp(eptr,"=",1)==0){
                                saveTag(b_value,eptr,ptr,0);
                                printf("body Val : %s\n",b_value);
                                eptr=ptr;
                            }
                            else{
                                saveTag(b_temp,eptr,ptr,0);
                                strcpy(b_tagname,b_temp);//시작태그 네임(img)
                                printf("bodyTag : %s\n",b_tagname);
                                eptr=ptr;
                            }
                            //속성, 밸류값 = 기준으로 분할하기   
                        }
                        else if(strncmp(ptr,"=",1)==0){
                            saveTag(b_attname,eptr,ptr,0);
                            printf("body Att : %s\n",b_attname);
                            eptr=ptr;
                        }
                        // else if(strncmp(ptr,"!",1)==0){
                        //     printf("find !");
                        //     while(strncmp(ptr,">",1)!=0){
                        //         ptr=&ptr[1]; 
                        //         break;
                        //     }
                        // }
                        else if(strncmp(ptr,">",1)==0){
                            saveTag(b_temp,eptr,ptr,0);
                            eptr=ptr;
                            //열림 태그 끝낫을때 텍스트</태그> 구분
                            
                            if(strcmp(b_temp,"/body")==0){
                                strcpy(b_element,b_temp);
                                printf("docele : %s\n",b_element);
                                break;
                            }
                            else if(strcmp(b_temp,"/body")!=0){
                                if(strcmp(b_temp,"p")==0){
                                    strcpy(b_tagname,b_temp);
                                    printf("bodyTag : %s\n",b_tagname);
                                }else{
                                    strcpy(b_value,b_temp);
                                    printf("bodyVal : %s\n",b_value);
                                }
                                ptr++;
                                if(strncmp(ptr+1,"\n",1)!=0){
                                    while(1){
                                        ptr=&ptr[1];
                                        if(strncmp(ptr,"<",1)==0){//<p>태그 텍스트
                                            saveTag(b_text,eptr,ptr,0);
                                            printf("bodyText : %s\n",b_text);
                                            // setPtr(&eptr,&ptr);
                                            eptr=ptr;
                                        }
                                        else if(strncmp(ptr,">",1)==0){
                                            saveTag(b_tagname,eptr,ptr,0);
                                            printf("bodyTag : %s\n",b_tagname);
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                if(strncmp(ptr,"\n",1)==0){//태그 없이 텍스트만 출력
                    eptr=&ptr[0];
                    saveTag(b_text,sptr,eptr,1);
                    printf("bodyText : %s\n",b_text);
                    isspace=0;
                }
            }
            if(strncmp(ptr,"\n",1)==0){
                isspace=0;
                if(strcmp(b_element,"/body")==0){
                    break;
                }
            }
        }
    }
}