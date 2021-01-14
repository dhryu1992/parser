#include "element.h"
#include "variable.h"
#include "cairo_variable.h"
#include <stdlib.h>


//int cairoImg_count;
void bodyParsing(char *b_element, char *b_text, char *b_tagname, 
                char *b_value, char *b_temp, char *b_attname) {
    char ftemp[100];
    int isspace = 0;
    
    if(strcmp(b_element, "body") == 0) {//바디 태그 내용 추출
        int i = 0;
        ptr = &ptr[1];//<body>에서 포인터를 한칸만 이동시 \n, 공백으로 출력
        while(1){
            // //printf("%d\n",arrnum);
            ptr = &ptr[1];
            if(strncmp(ptr, " ", 1) != 0 && isspace == 0) {
                sptr = ptr;
                isspace = 1;
                if(strncmp(ptr, "<", 1) != 0) {//텍스트+태그 출력, 12345<br>
                    while(strncmp(ptr, "\n", 1) != 0) {//전부 출력후 개행문자 확인시까지 반복
                        ptr = &ptr[1];
                        if(strncmp(ptr, "<", 1) == 0) {//텍스트 출력
                            eptr = ptr;
                            saveTag(b_text, sptr, eptr, 1);
                            copyChar(b_text);
                        }
                        else if(strncmp(ptr, ">", 1) == 0) {//태그 출력
                            saveTag(b_tagname, eptr, ptr, 2);
                            copyChar(b_tagname);
                            break;
                        }
                    }
                }
                else if(strncmp(ptr, "<", 1) == 0) {//태그 내부 출력
                    eptr = ptr;
                    sptr = ptr;
                    while(1){
                        ptr = &ptr[1];
                        if(strncmp(ptr, " ", 1) == 0) {//value값 
                            if(strncmp(eptr, "=", 1) == 0) {
                                saveTag(b_value, eptr, ptr, 0);
                                copyChar(b_value);
                                eptr = ptr;
								char *cairoImg_copy = NULL;
								char *cairo_eliminate = NULL;
								cairoImg_copy = (char*)malloc(sizeof(char) * strlen(b_value + 1));
									if(b_value != NULL) {
										while(cairo_img[cairoImg_count] != NULL) {
												cairoImg_count += 1;
													}
                                                strcpy(cairoImg_copy, b_value);
												eliminate(cairoImg_copy);
												cairo_img[cairoImg_count] = cairoImg_copy;
												printf("cairo_img[%d] = %s\n", cairoImg_count, cairoImg_copy);
												printf("cairo_img's value[%d]: %s\n", cairoImg_count, cairo_img[cairoImg_count]);
											}
                            }
                            else{
                                saveTag(b_temp, eptr, ptr, 0);
                                strcpy(b_tagname, b_temp);//시작태그 네임(img)
                                copyChar(b_tagname);
                                eptr = ptr;
                            }   
                        }
                        else if(strncmp(ptr, "=", 1) == 0) {//att값
                            sptr = ptr;
                            saveTag(b_attname, eptr, ptr, 0);
                            copyChar(b_attname);
                            eptr = ptr;
                        }
                        else if(strncmp(ptr, ">", 1) == 0) {//마지막 value값
                            saveTag(b_temp, eptr, ptr, 0);
                            eptr = ptr;
                            //열림 태그 끝낫을때 텍스트</태그> 구분
                            
                            if(strcmp(b_temp, "/body") == 0) {
                                strcpy(b_element, b_temp);
                                copyChar(b_element);
                                break;
                            }
                            else if(strcmp(b_temp, "/body") != 0) {
                                if(strncmp(sptr, "<", 1) == 0) {
                                    strcpy(b_tagname, b_temp);
                                    copyChar(b_tagname);
                                    //printf("%d\n",arrnum);
                                }else if(strncmp(sptr, "=", 1) == 0) {
                                    strcpy(b_value, b_temp);
                                    copyChar(b_value);
									char *cairoImg_copy = NULL;
									char *cairo_eliminate = NULL;
										while(cairo_img[cairoImg_count] != NULL) {
												cairoImg_count += 1;
										}
									cairoImg_copy = (char*)malloc(sizeof(char) * strlen(b_value + 1));
										if(b_value != NULL) {
											strcpy(cairoImg_copy, b_value);
											eliminate(cairoImg_copy);
											cairo_img[cairoImg_count] = cairoImg_copy;
											printf("cairo_img's last value[%d]: %s\n", cairoImg_count, cairo_img[cairoImg_count]);
										}
                                    copyChar("/img");
                                    //printf("%d\n",arrnum);
                                }
                                ptr++;
                                if(strncmp(ptr+1, "\n", 1) != 0) {
                                    while(1) {
                                        ptr = &ptr[1];
                                        if(strncmp(ptr, "<", 1) == 0) {//<p>태그 텍스트
                                            saveTag(b_text, eptr, ptr, 0);
											copyChar(b_text);
											int cairoText_count = 0;
											char *cairoText_copy = NULL;
											cairoText_copy = (char*)malloc(sizeof(char) * strlen(b_text + 1));
												if(b_text != NULL) {
													while(cairo_text[cairoText_count] != NULL) {
														cairoText_count += 1;
													}
														strcpy(cairoText_copy, b_text);
														cairo_text[cairoText_count] = cairoText_copy;
												}
											
                                            eptr = ptr;
                                        }
                                        else if(strncmp(ptr, ">", 1) == 0) {
                                            saveTag(b_tagname, eptr, ptr, 0);
                                            copyChar(b_tagname);
                                            //printf("%d\n",arrnum);
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                if(strncmp(ptr, "\n", 1) == 0) {//태그 없이 텍스트만 출력
                    eptr = &ptr[0];
                    saveTag(b_text, sptr, eptr, 1);
                    copyChar(b_text);
                    //printf("%d\n",arrnum);
                    isspace = 0;
                }
            }
            if(strncmp(ptr, "\n", 1) == 0) {
                isspace = 0;
                if(strcmp(b_element, "/body") == 0) {
                    break;
                }
            }
        }
    }
}
