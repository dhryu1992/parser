#include <stdio.h>
#include <string.h>


void saveTag(char *name, char *start, char *end, int num);
void fp_saveTag(char *name, char *start, char *end, char **current, int num);
void rp_saveTag(char *name, char *start, char *end, int num);
void copyTag(char *name, char *buf);
void setPtr(char **start, char **end);
