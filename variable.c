char buffer[MAX_LENGTH] = {0, };
char *temp = malloc(sizeof(char)*MAX_LENGTH);
char *element = malloc(sizeof(char)*MAX_LENGTH);
char *tagname = malloc(sizeof(char)*MAX_LENGTH);
char *context = malloc(sizeof(char)*MAX_LENGTH);
char *text = malloc(sizeof(char)*MAX_LENGTH);
char *attname = malloc(sizeof(char)*MAX_LENGTH);
char *value = malloc(sizeof(char)*MAX_LENGTH);

*context = 0; 
*text = 0;
*element = 0;
*tagname = 0;
*attname = 0;
*value = 0;
*temp = 0;

extern char *sptr = 0, *eptr = 0, *ptr = 0;

typedef char Element;

typedef struct elementNode{
    Element *data;
    struct eNode* parent;
    struct eNode* firstChild;
    struct eNode* lastChild;
    // struct eNode* childNodes[];
    struct eNode* nextSibling;
    struct eNode* prevSibling;
}eNode;

