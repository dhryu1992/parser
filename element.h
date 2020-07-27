#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH     1025

extern char buffer[MAX_LENGTH];
extern char *temp;
extern char *element;
extern char *tagname;
extern char *context;
extern char *text;
extern char *attname;
extern char *value;

void headparse();
void bodyparse();