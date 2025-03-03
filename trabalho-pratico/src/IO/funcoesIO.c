#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct File {
    FILE *file;
}*FICHEIRO;

FICHEIRO open_file (char *path,char * type) {
    FICHEIRO ficheiro = malloc(sizeof(struct File));
    ficheiro->file = fopen(path,type);
    return ficheiro;
}

void close_file (FICHEIRO file){
    fclose(file->file);
    free(file);
}

FILE *get_file(FICHEIRO f) {
    return f->file;
}

