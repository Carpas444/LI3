#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility/utility.h"




char **process_line(char *line) {
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
    char **info = calloc(10,sizeof(char*));
    int size = 10;
    int i;
    for (i=0;(info[i] = strsep(&line," ") ) !=NULL;i++) {
        if(i==size-1) {
            info=realloc(info,sizeof(info)*2);
            size *=2;
        }
        if (line != NULL && line[0] == '"'){
            line++;
            i++;
            info[i]=strsep(&line,"\"");
        }
    }
    return info;
}


char **parser_comandos(FILE *file,char **l) {
    char *line =NULL;
    size_t ln=0;
    if (getline(&line,&ln,file) != -1) {
        (*l)=line;
        return process_line(line);     
    }
    else {
        free (line);
        return NULL;
    }
}